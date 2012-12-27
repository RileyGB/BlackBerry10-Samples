#include "controllers/MapController.h"
#include "qjson/serializer.h"

#include <bb/data/JsonDataAccess>

#include <QObject>
#include <QVariant>

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/XmlDataModel>
#include <bb/cascades/Page>
#include <bb/cascades/WebView>

using namespace bb::cascades;
using namespace QJson;

/*
 *********************************************************************************
 * Constructor
 *********************************************************************************
 */

MapController::MapController(QObject *parent){

}

MapController::~MapController() {

}

/*
 *********************************************************************************
 * Setters
 *********************************************************************************
 */

void MapController::setWebView( QObject* webView ) {
	mWebView = qobject_cast<WebView *>(webView);

	if ( mWebView ) {
		mWebView->evaluateJavaScript("setPinsClickable(true)");
	}
}

void MapController::zoomOut() {
	if ( mWebView ) {
		mWebView->evaluateJavaScript("zoomOut()");
	}
}

void MapController::zoomIn() {
	if ( mWebView ) {
		mWebView->evaluateJavaScript("zoomIn()");
	}
}

void MapController::setZoomLevel( int zoomLevel ) {
	if ( mWebView ) {
		mWebView->evaluateJavaScript("setZoomLevel(" + QString::number(zoomLevel) + ")");
	}
}

void MapController::setMapPins( QVariantMap pins ) {
	if ( mWebView ) {
		Serializer serializer;
		QString mapPinsString( serializer.serialize(pins) );
		QString setPins;

		setPins.append( "addMapPins(" + mapPinsString + ")" );
		qDebug() << "Map Pins: " << setPins;

		mWebView->evaluateJavaScript( setPins );
	}
}


void MapController::setPinsClickable( bool clickable ) {

	if ( mWebView ) {
		if ( clickable )
			mWebView->evaluateJavaScript("setPinsClickable(true)");
		else
			mWebView->evaluateJavaScript("setPinsClickable(false)");
	}
}

WebView* MapController::getWebView() const{
	    return mWebView;
}
