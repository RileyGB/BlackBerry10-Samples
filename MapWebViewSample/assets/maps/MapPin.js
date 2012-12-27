
// ***************************************************************
// CONSTANTS
// ***************************************************************
var epsg4326 = new OpenLayers.Projection('EPSG:4326');
var epsg900913 = new OpenLayers.Projection('EPSG:900913');

//***************************************************************
// CREATORS
//***************************************************************

function createMapPin(latitude, longitude, pinId) {

 return new OpenLayers.Feature.Vector(new OpenLayers.Geometry.Point(longitude, latitude).transform(epsg4326, epsg900913), 
 	{ attributes: {'pinId': pinId} } 
 );

}

//***************************************************************
// GENERATORS
//***************************************************************

function generateMapPin(icon, iconFocus, width, height) {
	
	return new OpenLayers.Layer.Vector('Overlay', {
	      styleMap: new OpenLayers.StyleMap({
	    	  "default": new OpenLayers.Style({ 
	    		  	externalGraphic: icon,
	  	        	graphicWidth: width,
	  	        	graphicHeight: height,
	  	        	graphicYOffset: -height
	  	    	  }),
	    	  "select": new OpenLayers.Style({ 
	    		  externalGraphic: iconFocus,
	    		  graphicWidth: width,
	    		  graphicHeight: height,
	    		  graphicYOffset: -height
	    	  })
	      })
	    });
	
}

// Specify various map properties
function generateMapOptions() {
	
	 var options = {
		        maxScale: 500,
		        minScale: 20000000,
		        numZoomLevels: 12,
		        minResolution: "auto",
		        minExtent: new OpenLayers.Bounds(-1, -1, 1, 1),
		        maxResolution: "auto",
		        maxExtent: new OpenLayers.Bounds(-180, -90, 180, 90),
		        tileSize: new OpenLayers.Size(400,400),
		        controls: [
		        new OpenLayers.Control.Navigation(),
		        new OpenLayers.Control.ArgParser(),
		        new OpenLayers.Control.Attribution()
		    	]
		    };
	 
	 return options;
	
}

