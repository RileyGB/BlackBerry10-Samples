#include "WebImageView.h"
#include <QNetworkReply>
#include <QNetworkDiskCache>
#include <QDesktopServices>
#include <bb/cascades/Image>

using namespace bb::cascades;

QNetworkAccessManager * WebImageView::mNetManager = new QNetworkAccessManager();
QNetworkDiskCache * WebImageView::mNetworkDiskCache = new QNetworkDiskCache();

WebImageView::WebImageView() {

	// Initialize network cache
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
	// If you see Function "downloadProgress ( qint64 , qint64  ) is not defined"
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
	
	// Check status code
	QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
	if(statusCode==301 || statusCode==302 || statusCode==303 || statusCode==307){
		QByteArray header = reply->rawHeader("location");
        QUrl newUrl = QUrl::fromEncoded(header);
        if (!newUrl.isValid()){
        	newUrl = QUrl(QLatin1String(header));
        }
        if (!newUrl.isValid()){
        	newUrl = QUrl("");
        }
		setUrl(newUrl);
	}

	if (reply->error() == QNetworkReply::NoError){

		QUrl baseUrl = reply->url();
		QUrl redirection = reply->attribute(QNetworkRequest::RedirectionTargetAttribute).toUrl();
		// if redirection exists... Set the new Url
		if(redirection.isEmpty()){
			// Process reply
			QByteArray imageData = reply->readAll();

			// Set image from data
			setImage( Image(imageData) );

		}
		else{
			QUrl resolveUrl = baseUrl.resolved(redirection);
			setUrl(resolveUrl.toString());
			return;
		}

	}

		// Memory management
		reply->deleteLater();

	}

	void WebImageView::dowloadProgressed(qint64 bytes,qint64 total) {

		mLoading =  double(bytes)/double(total);
		emit loadingChanged();

	}
