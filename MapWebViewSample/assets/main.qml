import bb.cascades 1.0

Page {
    property variant mapType: 0
    // Receive messages from the webview
    function messageReceivedFromWebview(data) {
        // logic here
    }
    titleBar: TitleBar {
        id: titleBar
        visibility: ChromeVisibility.Visible
        title: "Map WebView Sample"
    }
    Container {
        layout: DockLayout {
        }
        Container {
            verticalAlignment: VerticalAlignment.Top
            horizontalAlignment: HorizontalAlignment.Center
            leftPadding: 20.0
            rightPadding: 20.0
            topPadding: 50.0
            Label {
                text: "This app uses OpenStreetMaps, OpenLayers and a WebView to connect to C++ and QML and provide a mapping solution."
                horizontalAlignment: HorizontalAlignment.Center
                multiline: true
            }
        }
        Container {
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Center
            Button {
                id: emptyMapButton
                text: "Empty Map"
                horizontalAlignment: HorizontalAlignment.Center
                onClicked: {
                    mapType = 0;
                    mapSheet.open();
                }
            }
            Button {
                id: onePinMapButton
                text: "Map with 1 pin"
                horizontalAlignment: HorizontalAlignment.Center
                onClicked: {
                    mapType = 1;
                    mapSheet.open();
                }
            }
            Button {
                id: multiplePinMapButton
                text: "Map with multiple pins"
                horizontalAlignment: HorizontalAlignment.Center
                onClicked: {
                    mapType = 2;
                    mapSheet.open();
                }
            }
        }
    }
    attachedObjects: [
        WebMapView {
            id: mapSheet
            onOpened: {
                _mapController.setWebView(mapSheet.mapView);
                setMapPins(mapType);
            }
            onClosed: {
                mapSheet.mapView.url = Qt.resolvedUrl("maps/map.html");
            }
            function setMapPins(typeOfMap) {
                // No map pins
                if (typeOfMap == 0) {
                    _mapController.setMapPins(getNoMapPins(), 0);
                    _mapController.setPinsClickable(true);
                }
                // One map pin
                if (typeOfMap == 1) {
                    _mapController.setMapPins(getOneMapPin(), 0);
                    _mapController.setPinsClickable(false);
                }
                // Multiple map pins
                if (typeOfMap == 2) {
                    _mapController.setMapPins(getMultipleMapPins(), 1);
                    _mapController.setPinsClickable(true);
                    _mapController.setZoomLevel(10);
                }
            }
            function getNoMapPins() {
                var noPins = {
                    "pins": [
                    ]
                };
                return noPins;
            }
            function getOneMapPin() {
                var onePin = {
                    "pins": [
                        {
                            "latitude": 29.77,
                            "longitude": -95.41,
                            "pinId": "Pin 1"
                        }
                    ]
                };
                return onePin;
            }
            function getMultipleMapPins() {
                var multiplePins = {
                    "pins": [
                        {
                            "latitude": 29.77,
                            "longitude": -95.41,
                            "pinId": "Pin 1"
                        },
                        {
                            "latitude": 29.72,
                            "longitude": -95.34,
                            "pinId": "Pin 2"
                        },
                        {
                            "latitude": 29.64,
                            "longitude": -95.43,
                            "pinId": "Pin 3"
                        }
                    ]
                };
                return multiplePins;
            }
        }
    ]
}
