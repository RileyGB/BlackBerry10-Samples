import bb.cascades 1.0

// The sheet that contains the map view

Sheet {
    property alias mapView: webViewMap
    id: mapSheet
    peekEnabled: false
    onOpenedChanged: {
        webViewMap.enabled = true; // ensure pins can be clicked
    }
    Page {
        titleBar: TitleBar {
            id: titleBarMapSheet
            title: "Map"
            visibility: ChromeVisibility.Visible
            acceptAction: ActionItem {
                title: "Close"
                onTriggered: {
                    onClicked: mapSheet.close()
                }
            }
        }
        objectName: "mapPage"
        Container {
            background: Color.White
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Center
            WebView {
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                id: webViewMap
                preferredWidth: 768.0
                preferredHeight: 1200.0
                url: Qt.resolvedUrl("maps/map.html")
                settings.zoomToFitEnabled: true
                onMessageReceived: {
                    // Ensure that we don't double click
                    if (webViewMap.enabled) {
                        messageReceivedFromWebview(message.data);
                        webViewMap.enabled = false;
                    }
                }
            }
            Container {
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                topPadding: 15.0
                bottomPadding: 15.0
                layout: StackLayout {
                    orientation: LayoutOrientation.LeftToRight
                }
                Button {
                    text: "Zoom In"
                    id: zoomInButton
                    onClicked: {
                        _mapController.zoomIn();
                    }
                }
                Button {
                    text: "Zoom Out"
                    id: zoomOutButton
                    onClicked: {
                        _mapController.zoomOut();
                    }
                }
            }
        }
    }
}
