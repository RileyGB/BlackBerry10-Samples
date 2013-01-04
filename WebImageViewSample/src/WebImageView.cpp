#include "WebImageView.h"
#include <QNetworkReply>
#include <bb/cascades/Image>

using namespace bb::cascades;

QNetworkAccessManager * WebImageView::mNetManager = new QNetworkAccessManager;

WebImageView::WebImageView() {


}

const QUrl& WebImageView::url() const {
	return mUrl;
}

void WebImageView::setUrl(const QUrl& url) {

	// Variables
	mUrl = url;
	mLoading = 0;

	// Get image from cache
	if( isImageInCache() ) {
		setImage( getImageFromCache() );
		mLoading = 1.0;
		return;
	}

	// Otherwise, get image from web
	QNetworkReply * reply = mNetManager->get(QNetworkRequest(url));
	connect(reply,SIGNAL(finished()), this, SLOT(imageLoaded()));
	connect(reply,SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(dowloadProgressed(qint64,qint64)));

	//
	// Note:
	// If you see Function "downloadProgress ( qint64 , qint64  )"
	// Simply close this file, delete the error and compile the project
	//

	emit urlChanged();
}

double WebImageView::loading() const {
	return mLoading;
}

void WebImageView::imageLoaded() {

	QNetworkReply * reply = qobject_cast<QNetworkReply*>(sender());

	QByteArray imageData = reply->readAll();
	setImage( Image(imageData) );
	saveImageInCache( imageData );

	reply->deleteLater();

}

void WebImageView::dowloadProgressed(qint64 bytes,qint64 total) {

	mLoading =  double(bytes)/double(total);
	emit loadingChanged();

}

bool WebImageView::isImageInCache() {

	// Check if we've create image cache map in persistent storage
	if( !mSettings.contains("ImageCache") ) {
		QVariantMap emptyImageCacheMap;
		mSettings.setValue("ImageCache", emptyImageCacheMap);
	}

	// Create a map for our image cache
	QVariantMap imageCacheMap = mSettings.value("ImageCache").toMap();

	// Check for our image
	if( imageCacheMap.contains( mUrl.toString() ) && imageCacheMap.value( mUrl.toString() ).toByteArray().size() > 0 ) {
		return true;
	}
	else {
		return false;
	}

}

QByteArray WebImageView::getImageFromCache() {

	// Get image cache
	QVariantMap imageCacheMap = mSettings.value("ImageCache").toMap();

	// Return image
	return imageCacheMap.value( mUrl.toString() ).toByteArray();

}

void  WebImageView::saveImageInCache(QByteArray imageData) {

	// Variables
	QVariantMap imageCacheMap;

	// Get image cache
	if( !mSettings.contains("ImageCache") ) {
		mSettings.setValue("ImageCache", imageCacheMap);
	}
	else {
		imageCacheMap = mSettings.value("ImageCache").toMap();
	}

	// Save image to cache
	imageCacheMap.insert( mUrl.toString(), imageData );

	// Save image cache
	mSettings.setValue("ImageCache", imageCacheMap);

}




