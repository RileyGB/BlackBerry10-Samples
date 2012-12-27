#include "MapWebViewSample.hpp"
#include "controllers/MapController.h"
#include "controllers/LocationSession.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

using namespace bb::cascades;

MapWebViewSample::MapWebViewSample(bb::cascades::Application *app)
: QObject(app)
{
    // create scene document from main.qml asset
    // set parent to created document to ensure it exists for the whole application lifetime
    mQmlDocument = QmlDocument::create("asset:///main.qml").parent(this);

    // Start getting GPS location
    initializeLocation();

    // Create a controller for maps
    createMapController();

    // create root object for the UI
    AbstractPane *root = mQmlDocument->createRootObject<AbstractPane>();
    // set created root object as a scene
    app->setScene(root);
}


void MapWebViewSample::initializeLocation() {

	// Create location sessions
	LocationSession *locationSession = new LocationSession(this, false);

	// Set location properties
	locationSession->positionSource()->setPreferredPositioningMethods(QGeoPositionInfoSource::AllPositioningMethods);
	locationSession->positionSource()->setUpdateInterval(10 * 1000);
	locationSession->positionSource()->setProperty("canRunInBackground", true);

	// Get updates
	locationSession->startUpdates();

	// Set context property
	mQmlDocument->setContextProperty("_locationSession", locationSession);

}

void MapWebViewSample::createMapController() {

	// Create map controller
	MapController *mapController = new MapController(this);

	// Set context property
	mQmlDocument->setContextProperty("_mapController", mapController);

}
