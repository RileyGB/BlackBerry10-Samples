#ifndef MAPCONTROLLER_H_
#define MAPCONTROLLER_H_

#include <bb/cascades/GroupDataModel>
#include <bb/cascades/WebView>
#include <bb/cascades/QmlDocument>
#include <bb/data/JsonDataAccess>
#include <QFile>

using namespace bb::data;
using namespace bb::cascades;

class MapController: public QObject {
	Q_OBJECT

public:

	// Constructor
	MapController(QObject *parent = 0);
	virtual ~MapController();

	Q_INVOKABLE void setWebView(QObject* webView);
	Q_INVOKABLE void zoomIn();
	Q_INVOKABLE void zoomOut();
	Q_INVOKABLE void setZoomLevel( int zoomLevel );
	Q_INVOKABLE void setMapPins(QVariantMap pins);
	Q_INVOKABLE void setPinsClickable( bool clickable );

//	signals:

//private slots:

private:
	// Network manager
	bb::cascades::WebView* getWebView() const;
	QPointer<bb::cascades::WebView> mWebView;
	QmlDocument *mQmlDocument;
};

#endif /* MAPCONTROLLER_H_ */
