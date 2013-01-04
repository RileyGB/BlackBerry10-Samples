#ifndef WEBIMAGEVIEW_H_
#define WEBIMAGEVIEW_H_

#include <bb/cascades/ImageView>
#include <QNetworkAccessManager>
#include <QUrl>
using namespace bb::cascades;

class WebImageView: public bb::cascades::ImageView {
	Q_OBJECT
	Q_PROPERTY (QUrl url READ url WRITE setUrl NOTIFY urlChanged)
	Q_PROPERTY (float loading READ loading NOTIFY loadingChanged)

public:
	WebImageView();
	const QUrl& url() const;
	double loading() const;

	public Q_SLOTS:
	void setUrl(const QUrl& url);

	private Q_SLOTS:
	void imageLoaded();
	void dowloadProgressed(qint64,qint64);

	signals:
	void urlChanged();
	void loadingChanged();


private:
	bool isImageInCache();
	QByteArray getImageFromCache();
	void saveImageInCache(QByteArray imageData);


	static QNetworkAccessManager * mNetManager;
	QUrl mUrl;
	float mLoading;
	QSettings mSettings;
};

#endif /* WEBIMAGEVIEW_H_ */
