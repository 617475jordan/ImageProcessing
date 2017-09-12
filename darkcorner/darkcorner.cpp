//£®¡¡Ω«: strength∑∂ŒßŒ™[0.0f, 1.0f], ∞µΩ«: strength∑∂ŒßŒ™[-1.0f, 0.0f]£©£∫
void ImageVignetting(BMPINFO *pSrcBitmap, float strength)  
{  
    int width = pSrcBitmap->lWidth;  
    int height = pSrcBitmap->lHeight;  
    float radio = 0.0;  
    float maxLen = (float)MAX(width, height);  
    float cx = maxLen * 0.5f;  
    float cy = maxLen * 0.5f;  
    float maxDist = cx*cx + cy*cy;  
    uchar* pSrcData = pSrcBitmap->pPlane[0];  
  
    if (strength > 0.0f)  
    {  
        // ¡¡Ω«  
        for (int i = 0; i < height; i++)  
        {  
            for (int j = 0; j < width; j++, pSrcData += 4)  
            {  
                float nx = (float)maxLen * j / width;  
                float ny = (float)maxLen * i / height;  
                float curDist = (nx - cx)*(nx - cx) + (ny - cy)*(ny - cy);  
                radio = curDist / maxDist;  
                // radio *= radio;  
                radio *= strength;  
                pSrcData[BLUE] = (uchar)CLAMP0255(pSrcData[BLUE]*(1.0f - radio) + SCREEN_XY(pSrcData[BLUE], 230)*radio);  
                pSrcData[GREEN] = (uchar)CLAMP0255(pSrcData[GREEN]*(1.0f - radio) + SCREEN_XY(pSrcData[GREEN], 230)*radio);  
                pSrcData[RED] = (uchar)CLAMP0255(pSrcData[RED]*(1.0f - radio) + SCREEN_XY(pSrcData[RED], 230)*radio);  
            }  
        }  
    }  
    else  
    {  
        // ∞µΩ«  
        for (int i = 0; i < height; i++)  
        {  
            for (int j = 0; j < width; j++, pSrcData += 4)  
            {  
                float nx = (float)maxLen * j / width;  
                float ny = (float)maxLen * i / height;  
                float curDist = (nx - cx)*(nx - cx) + (ny - cy)*(ny - cy);  
                radio = curDist / maxDist;  
                // radio *= radio;  
                radio *= strength;  
                radio = 1.0f + radio;  
                pSrcData[BLUE] = (uchar)CLAMP0255(pSrcData[BLUE]*radio);  
                pSrcData[GREEN] = (uchar)CLAMP0255(pSrcData[GREEN]*radio);  
                pSrcData[RED] = (uchar)CLAMP0255(pSrcData[RED]*radio);  
            }  
        }  
    }  
}