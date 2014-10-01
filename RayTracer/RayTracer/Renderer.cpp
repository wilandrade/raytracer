#include "Renderer.h"
#include "Scene.h"
#include "Tracer.h"


void Renderer::Render(Scene* scene, int w, int h)
{
	
	std::cout << "Drawing Scene ... \n";

	TRACER->SetCurrentScene(scene); //set scene we'll be rendering

	int totalPixels = w * h;				
	Color3 * pixelData = new Color3[totalPixels];	//allocate memory for pixel data

	int totalSamples = 64; //total amount of samples used for anti-aliasing
	double tempRand = 0; //random number holder
	double precision = 10.0; //precision of random number
	//start ray casting by iterating through each pixel on the screen
	int curPixel = 0;
	for(int y = 0; y < h; y++)
	{
		//double ny = (double)y/h;
		std::cout << ".";
		
		for(int x = 0; x < w; x++)
		{
			//double nx = (double)x/w;
			//pixelData[curPixel] = TRACER->Trace(nx, ny);
			
			for(int ss = 0; ss < totalSamples; ss++)
			{
				tempRand = (rand() % ((int)precision*2)) - precision;
				tempRand = (double)tempRand/precision;
				double ssnx = ((double)x + tempRand) / w;

				tempRand = (rand() % ((int)precision*2)) - precision;
				tempRand = (double)tempRand/precision;
				double ssny = ((double)y + tempRand) / h;

				pixelData[curPixel] += TRACER->Trace(ssnx, ssny)/(double)totalSamples; //assign color values
			}
			
			curPixel++;

			//std::cout << (y*x)/totalSamples << "% done.\n";
		}

	}


	//save image
	std::string fileName = "test.raw";
	WriteToFile(fileName, pixelData, w, h);
}

bool Renderer::WriteToFile(std::string fileName, Color3 *pixelData, int w, int h)
{

	std::cout << "Writing to File \n" ;


	//-------------------------------
	//WRITE TO FILE CODES FROM JORDAN
	//-------------------------------
	//-----------------------------------------------------------------------

	//open file in binary write
	std::ofstream myfile(fileName.c_str(),std::ios_base::binary);

    int totalPixels = w * h;
    for( int curPixel = 0; curPixel < totalPixels; curPixel++ )
    {   
        //got this from Paul Edmondson 1/30/2007 -->[PE]
        unsigned char cval;
        //write red pixel
        cval = (unsigned char)(pixelData[curPixel].x * 255);
        myfile.write((char *)&cval, 1);

        //write blue pixel
        cval = (unsigned char)(pixelData[curPixel].y * 255);
        myfile.write((char *)&cval, 1);

        //write green pixel
        cval = (unsigned char)(pixelData[curPixel].z * 255);
        myfile.write((char *)&cval, 1);
        //end -->[PE]
    }
    //close binary file
    myfile.close();


	//-----------------------------------------------------------------------



	bool bSuccess = true;

	return bSuccess;
}