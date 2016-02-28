/*
 * This demo provides the samples for reading GeoTiff and Shapefile.
 */

/* 
 * File:   main.cpp
 */

#include <cstdlib>
#include <stdio.h>
#include <cstdio>
#include <string>
#include "gdal_priv.h"      // For C++ and C
#include "cpl_conv.h"       // for CPLMalloc()


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    /***************************** Read GeoTiff *******************************/
    // dataset name
    string fileName = "datasamples/SatelliteDataSample.tif"; 
    
    // Open the file
    GDALAllRegister();
    GDALDatasetH    hDataset = GDALOpen( fileName.c_str(), GA_ReadOnly ); 
    
    // Get dataset info:
    GDALDriverH   hDriver = GDALGetDatasetDriver( hDataset );
    double        adfGeoTransform[6];
    if( GDALGetGeoTransform( hDataset, adfGeoTransform ) == CE_None ) {
        printf( "\nOrigin = (%.6f, %.6f)\n", adfGeoTransform[0], adfGeoTransform[3] );
        printf( "\n\nPixel Size = (%.6f, %.6f)\n", adfGeoTransform[1], adfGeoTransform[5] );
    }
    
    // get image size (columns, rows, bands)
    printf( "\nImage Size is %d x %d x %d\n", GDALGetRasterXSize( hDataset ), 
        GDALGetRasterYSize( hDataset ), GDALGetRasterCount( hDataset ) );
    
    // Get coordinate system
    if( GDALGetProjectionRef( hDataset ) != NULL )
        printf( "\nProjection is `%s'\n", GDALGetProjectionRef( hDataset ) );

    // Get band 1 from satellite image
    GDALDatasetH hBand = GDALGetRasterBand( hDataset, 1 );
    
    
    /*************************** Read Shapefile *******************************/
    printf( "Reading shapefile\n" );
    // Open Shapefe
    GDALDatasetH hDS;
    hDS = GDALOpenEx( "datasamples/Cities.shp", GDAL_OF_VECTOR, NULL, NULL, NULL );
    if( hDS == NULL ) {
        printf( "Open failed.\n" ); exit( 1 );
    }
    
    // load data layer
    OGRLayerH hLayer;
    hLayer = GDALDatasetGetLayerByName( hDS, "Cities" );
    
    // loop on the feature
    OGRFeatureH hFeature;
    OGR_L_ResetReading(hLayer);
    while( (hFeature = OGR_L_GetNextFeature(hLayer)) != NULL ){
        OGRFeatureDefnH hFDefn = OGR_L_GetLayerDefn(hLayer);
        int iField;
        printf( "\n" );
        // print the attributes
        for( iField = 0; iField < OGR_FD_GetFieldCount(hFDefn); iField++ )
        {
            OGRFieldDefnH hFieldDefn = OGR_FD_GetFieldDefn( hFDefn, iField );
            if( OGR_Fld_GetType(hFieldDefn) == OFTInteger )
                printf( "%d,", OGR_F_GetFieldAsInteger( hFeature, iField ) );
            else if( OGR_Fld_GetType(hFieldDefn) == OFTInteger64 )
                printf( CPL_FRMT_GIB ",", OGR_F_GetFieldAsInteger64( hFeature, iField ) );
            else if( OGR_Fld_GetType(hFieldDefn) == OFTReal )
                printf( "%.3f,", OGR_F_GetFieldAsDouble( hFeature, iField) );
            else if( OGR_Fld_GetType(hFieldDefn) == OFTString )
                printf( "%20s,", OGR_F_GetFieldAsString( hFeature, iField) );
            else
                printf( "%20s,", OGR_F_GetFieldAsString( hFeature, iField) );
        }
        
        // print geometry
        OGRGeometryH hGeometry;
        hGeometry = OGR_F_GetGeometryRef(hFeature);
        if( hGeometry != NULL && wkbFlatten(OGR_G_GetGeometryType(hGeometry)) == wkbPoint ) {
            printf( "%10.4f,%10.4f", OGR_G_GetX(hGeometry, 0), OGR_G_GetY(hGeometry, 0) );
        } else {
            printf( "no point geometry\n" );
        }
    }

    return 0;
}

