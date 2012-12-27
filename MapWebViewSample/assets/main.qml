import bb.cascades 1.0

Page {
    titleBar: TitleBar {
        id: titleBar
        visibility: ChromeVisibility.Visible
        title: "Map WebView Sample"
        branded: TriBool.False
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
            }
            Button {
                id: onePinMapButton
                text: "Map with 1 pin"
                horizontalAlignment: HorizontalAlignment.Center
            }
            Button {
                id: multiplePinMapButton
                text: "Map with multiple pins"
                horizontalAlignment: HorizontalAlignment.Center
            }
        }
    }
}
