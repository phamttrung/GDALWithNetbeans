/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Trung
 *
 * Created on February 24, 2016, 10:35 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include "gdal_priv.h"      // For C++ and C
#include "cpl_conv.h"       // for CPLMalloc()


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
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

    return 0;
}

