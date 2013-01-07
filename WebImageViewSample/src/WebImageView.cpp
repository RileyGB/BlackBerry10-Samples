#include "WebImageView.h"
#include <QNetworkReply>
#include <QNetworkDiskCache>
#include <QDesktopServices>
#include <bb/cascades/Image>

using namespace bb::cascades;

QNetworkAccessManager * WebImageView::mNetManager = new QNetworkAccessManager();

WebImageView::WebImageView() {

	// Initialize network cache
	mNetworkDiskCache = new QNetworkDiskCache(this);
	mNetworkDiskCache->setCacheDirectory(QDesktopServices::storageLocation(QDesktopServices::CacheLocation));

	// Set cache in manager
	mNetManager->setCache(mNetworkDiskCache);

}

const QUrl& WebImageView::url() const {
	return mUrl;
}

void WebImageView::setUrl(const QUrl& url) {

	// Variables
	mUrl = url;
	mLoading = 0;

	// Reset the image
	resetImage();

	// Create request
	QNetworkRequest request;
	request.setAttribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::PreferCache);
	request.setUrl(url);

	// Create reply
	QNetworkReply * reply = mNetManager->get(request);
	QObject::connect(reply,SIGNAL(finished()), this, SLOT(imageLoaded()));
	QObject::connect(reply,SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(dowloadProgressed(qint64,qint64)));

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

	// Get reply
	QNetworkReply * reply = qobject_cast<QNetworkReply*>(sender());

	// Process reply
	QByteArray imageData = reply->readAll();

	// Set image from data
	setImage( Image(imageData) );

	// Memory management
	reply->deleteLater();

}

void WebImageView::dowloadProgressed(qint64 bytes,qint64 total) {

	mLoading =  double(bytes)/double(total);
	emit loadingChanged();

}
