#include "halconObjectRecognition.h"


halconObjectRecognition::halconObjectRecognition()
{
}


halconObjectRecognition::~halconObjectRecognition()
{
}

void halconObjectRecognition::initialize()
{
	SetSystem("width", 480);
	SetSystem("height", 640);
}

// Procedures 
// External procedures 
// Chapter: Graphics / Text
// Short Description: Set font independent of OS 
void halconObjectRecognition::set_display_font(HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font, HTuple hv_Bold,
	HTuple hv_Slant)
{

	// Local iconic variables

	// Local control variables
	HTuple  hv_OS, hv_Fonts, hv_Style, hv_Exception;
	HTuple  hv_AvailableFonts, hv_Fdx, hv_Indices;

	//This procedure sets the text font of the current window with
	//the specified attributes.
	//
	//Input parameters:
	//WindowHandle: The graphics window for which the font will be set
	//Size: The font size. If Size=-1, the default of 16 is used.
	//Bold: If set to 'true', a bold font is used
	//Slant: If set to 'true', a slanted font is used
	//
	GetSystem("operating_system", &hv_OS);
	// dev_get_preferences(...); only in hdevelop
	// dev_set_preferences(...); only in hdevelop
	if (0 != (HTuple(hv_Size == HTuple()).TupleOr(hv_Size == -1)))
	{
		hv_Size = 16;
	}
	if (0 != ((hv_OS.TupleSubstr(0, 2)) == HTuple("Win")))
	{
		//Restore previous behaviour
		hv_Size = (1.13677*hv_Size).TupleInt();
	}
	if (0 != (hv_Font == HTuple("Courier")))
	{
		hv_Fonts.Clear();
		hv_Fonts[0] = "Courier";
		hv_Fonts[1] = "Courier 10 Pitch";
		hv_Fonts[2] = "Courier New";
		hv_Fonts[3] = "CourierNew";
	}
	else if (0 != (hv_Font == HTuple("mono")))
	{
		hv_Fonts.Clear();
		hv_Fonts[0] = "Consolas";
		hv_Fonts[1] = "Menlo";
		hv_Fonts[2] = "Courier";
		hv_Fonts[3] = "Courier 10 Pitch";
		hv_Fonts[4] = "FreeMono";
	}
	else if (0 != (hv_Font == HTuple("sans")))
	{
		hv_Fonts.Clear();
		hv_Fonts[0] = "Luxi Sans";
		hv_Fonts[1] = "DejaVu Sans";
		hv_Fonts[2] = "FreeSans";
		hv_Fonts[3] = "Arial";
	}
	else if (0 != (hv_Font == HTuple("serif")))
	{
		hv_Fonts.Clear();
		hv_Fonts[0] = "Times New Roman";
		hv_Fonts[1] = "Luxi Serif";
		hv_Fonts[2] = "DejaVu Serif";
		hv_Fonts[3] = "FreeSerif";
		hv_Fonts[4] = "Utopia";
	}
	else
	{
		hv_Fonts = hv_Font;
	}
	hv_Style = "";
	if (0 != (hv_Bold == HTuple("true")))
	{
		hv_Style += HTuple("Bold");
	}
	else if (0 != (hv_Bold != HTuple("false")))
	{
		hv_Exception = "Wrong value of control parameter Bold";
		throw HException(hv_Exception);
	}
	if (0 != (hv_Slant == HTuple("true")))
	{
		hv_Style += HTuple("Italic");
	}
	else if (0 != (hv_Slant != HTuple("false")))
	{
		hv_Exception = "Wrong value of control parameter Slant";
		throw HException(hv_Exception);
	}
	if (0 != (hv_Style == HTuple("")))
	{
		hv_Style = "Normal";
	}
	QueryFont(hv_WindowHandle, &hv_AvailableFonts);
	hv_Font = "";
	{
		HTuple end_val48 = (hv_Fonts.TupleLength()) - 1;
		HTuple step_val48 = 1;
		for (hv_Fdx = 0; hv_Fdx.Continue(end_val48, step_val48); hv_Fdx += step_val48)
		{
			hv_Indices = hv_AvailableFonts.TupleFind(HTuple(hv_Fonts[hv_Fdx]));
			if (0 != ((hv_Indices.TupleLength()) > 0))
			{
				if (0 != (HTuple(hv_Indices[0]) >= 0))
				{
					hv_Font = HTuple(hv_Fonts[hv_Fdx]);
					break;
				}
			}
		}
	}
	if (0 != (hv_Font == HTuple("")))
	{
		throw HException("Wrong value of control parameter Font");
	}
	hv_Font = (((hv_Font + "-") + hv_Style) + "-") + hv_Size;
	SetFont(hv_WindowHandle, hv_Font);
	// dev_set_preferences(...); only in hdevelop
	return;
}

// Chapter: Graphics / Text
// Short Description: This procedure displays 'Click 'Run' to continue' in the lower right corner of the screen. 
void halconObjectRecognition::disp_continue_message(HTuple hv_WindowHandle, HTuple hv_Color, HTuple hv_Box)
{

	// Local iconic variables

	// Local control variables
	HTuple  hv_GenParamName, hv_GenParamValue, hv_ContinueMessage;

	//This procedure displays 'Press Run (F5) to continue' in the
	//lower right corner of the screen.
	//It uses the procedure disp_message.
	//
	//Input parameters:
	//WindowHandle: The window, where the text shall be displayed
	//Color: defines the text color.
	//   If set to '' or 'auto', the currently set color is used.
	//Box: If set to 'true', the text is displayed in a box.
	//
	//Convert the parameter Box to generic parameters.
	hv_GenParamName = HTuple();
	hv_GenParamValue = HTuple();
	if (0 != ((hv_Box.TupleLength()) > 0))
	{
		if (0 != (HTuple(hv_Box[0]) == HTuple("false")))
		{
			//Display no box
			hv_GenParamName = hv_GenParamName.TupleConcat("box");
			hv_GenParamValue = hv_GenParamValue.TupleConcat("false");
		}
		else if (0 != (HTuple(hv_Box[0]) != HTuple("true")))
		{
			//Set a color other than the default.
			hv_GenParamName = hv_GenParamName.TupleConcat("box_color");
			hv_GenParamValue = hv_GenParamValue.TupleConcat(HTuple(hv_Box[0]));
		}
	}
	if (0 != ((hv_Box.TupleLength()) > 1))
	{
		if (0 != (HTuple(hv_Box[1]) == HTuple("false")))
		{
			//Display no shadow.
			hv_GenParamName = hv_GenParamName.TupleConcat("shadow");
			hv_GenParamValue = hv_GenParamValue.TupleConcat("false");
		}
		else if (0 != (HTuple(hv_Box[1]) != HTuple("true")))
		{
			//Set a shadow color other than the default.
			hv_GenParamName = hv_GenParamName.TupleConcat("shadow_color");
			hv_GenParamValue = hv_GenParamValue.TupleConcat(HTuple(hv_Box[1]));
		}
	}
	//
	if (0 != (hv_Color == HTuple("")))
	{
		//disp_text does not accept an empty string for Color.
		hv_Color = HTuple();
	}
	//
	//Display the message.
	/*hv_ContinueMessage = "Press Run (F5) to continue";
	DispText(hv_WindowHandle, hv_ContinueMessage, "window", "bottom", "right", hv_Color,
		hv_GenParamName, hv_GenParamValue);*/
	return;
}

// Main procedure 
void halconObjectRecognition::action()
{

	// Local iconic variables
	HObject  ho_ModelImage, ho_ModelROI;
	HObject	ho_tmpModelImage, ho_ImageROI;
	HObject  ho_ShapeModelImage, ho_ShapeModelRegion, ho_ShapeModel;
	HObject  ho_SearchImage, ho_ModelAtNewPosition;

	// Local control variables
	HTuple  hv_FGHandle, hv_Pointer, hv_Type, hv_Width, hv_tmpFGHandle;
	HTuple  hv_Height, hv_WindowHandle, hv_Radius;
	HTuple  hv_ModelID, hv_i, hv_RowCheck, hv_ColumnCheck, hv_AngleCheck;
	HTuple  hv_Score, hv_j, hv_MovementOfObject, hv_RowArrowHead;
	HTuple  hv_ColumnArrowHead;
	vector<HTuple>  hv_vecModelID;
	vector<HObject>	 ho_vecShapeModel;

	vector<HTuple> hv_width, hv_height, hv_Row, hv_Column;
	int m_iImgNum = 1;


	hv_Row.push_back(60);
	hv_Column.push_back(180);
	hv_width.push_back(620);
	hv_height.push_back(320);
	//------------------------------------------------------------------------------------------------
	//This example program searches for multiple instances of a security ring.
	//------------------------------------------------------------------------------------------------
	//general configuration of HDevelop
	// dev_update_window(...); only in hdevelop
	//image acquisition and window size

	char m_charfileName[100];
	for (int j = 0; j < m_iImgNum; j++)
	{
		sprintf(m_charfileName, "..\\caliper\\test9\\src\\%d.jpg", j + 1);

		OpenFramegrabber("File", 1, 1, 0, 0, 0, 0, "default", -1, "default", -1, "default",
			m_charfileName, "default", -1, 1, &hv_FGHandle);
		GrabImage(&ho_ModelImage, hv_FGHandle);


		GetImagePointer1(ho_ModelImage, &hv_Pointer, &hv_Type, &hv_Width, &hv_Height);
		if (HDevWindowStack::IsOpen())
			CloseWindow(HDevWindowStack::Pop());
		SetWindowAttr("background_color", "white");
		OpenWindow(0, 0, hv_Width, hv_Height, 0, "visible", "", &hv_WindowHandle);
		HDevWindowStack::Push(hv_WindowHandle);
		if (HDevWindowStack::IsOpen())
			SetPart(HDevWindowStack::GetActive(), 0, 0, hv_Height - 1, hv_Width - 1);
		if (HDevWindowStack::IsOpen())
			DispObj(ho_ModelImage, HDevWindowStack::GetActive());
		//colors and other settings for the visualization
		if (HDevWindowStack::IsOpen())
			SetColor(HDevWindowStack::GetActive(), "blue");
		if (HDevWindowStack::IsOpen())
			SetDraw(HDevWindowStack::GetActive(), "margin");
		if (HDevWindowStack::IsOpen())
			SetLineWidth(HDevWindowStack::GetActive(), 2);
		//set_display_font(hv_WindowHandle, 14, "mono", "true", "false");
		//disp_continue_message(hv_WindowHandle, "black", "true");

		// stop(...); only in hdevelop
		//-------------------  start of the application  ----------------
		//step 1: select the model object

		//hv_Radius = 103;
		//GenCircle(&ho_ModelROI, hv_Row, hv_Column, hv_Radius);
		GenRectangle1(&ho_ModelROI, hv_Row[j], hv_Column[j], hv_width[j], hv_height[j]);
		if (HDevWindowStack::IsOpen())
			DispObj(ho_ModelROI, HDevWindowStack::GetActive());
		disp_continue_message(hv_WindowHandle, "black", "true");
		// stop(...); only in hdevelop
		//step 2: inspect the model region
		ReduceDomain(ho_ModelImage, ho_ModelROI, &ho_ImageROI);
		InspectShapeModel(ho_ImageROI, &ho_ShapeModelImage, &ho_ShapeModelRegion, 1, 30);
		//if (HDevWindowStack::IsOpen())
		//	ClearWindow(HDevWindowStack::GetActive());
		//if (HDevWindowStack::IsOpen())
		//	DispObj(ho_ShapeModelRegion, HDevWindowStack::GetActive());
		//disp_continue_message(hv_WindowHandle, "black", "true");
		// stop(...); only in hdevelop
		//step 3: create the model

		//ReduceDomain(ho_ModelImage, ho_ModelROI, &ho_ImageROI);
		CreateShapeModel(ho_ImageROI, "auto", 0, HTuple(360).TupleRad(), "auto", "none",
			"ignore_global_polarity", 30, 10, &hv_ModelID);
		/*CreateScaledShapeModel(ho_ImageROI, 5, HTuple(-180).TupleRad(), HTuple(180).TupleRad(),
		"auto", 0.8, 1.0, "auto", "none", "ignore_global_polarity", 40, 10, &hv_ModelID);*/
		GetShapeModelContours(&ho_ShapeModel, hv_ModelID, 1);
		disp_continue_message(hv_WindowHandle, "black", "true");

		hv_vecModelID.push_back(hv_ModelID);
		ho_vecShapeModel.push_back(ho_ShapeModel);

		Sleep(2000);
	}
	cout << "size:" << hv_vecModelID.size() << endl;




	// stop(...); only in hdevelop
	//step 4: find the object in other images
	int t = clock();
	int i = 0;
	for (hv_i = 1; hv_i <= 10; hv_i += 1)
	{
		++i;
		sprintf(m_charfileName, "..\\caliper\\test9\\dst\\%d.jpg", i);
		OpenFramegrabber("File", 1, 1, 0, 0, 0, 0, "default", -1, "default", -1, "default",
			m_charfileName, "default", -1, 1, &hv_tmpFGHandle);
		GrabImage(&ho_SearchImage, hv_tmpFGHandle);
		if (HDevWindowStack::IsOpen())
			DispObj(ho_SearchImage, HDevWindowStack::GetActive());
		for (int j = 0; j < m_iImgNum; j++)
		{

			FindShapeModel(ho_SearchImage, hv_vecModelID[j], 0, HTuple(360).TupleRad(), 0.6, 0,
				0.35, "least_squares", 0, 0., &hv_RowCheck, &hv_ColumnCheck, &hv_AngleCheck,
				&hv_Score);
			{
				HTuple end_val47 = (hv_Score.TupleLength()) - 1;
				HTuple step_val47 = 1;
				for (hv_j = 0; hv_j.Continue(end_val47, step_val47); hv_j += step_val47)
				{
					VectorAngleToRigid(0, 0, 0, HTuple(hv_RowCheck[hv_j]), HTuple(hv_ColumnCheck[hv_j]),
						HTuple(hv_AngleCheck[hv_j]), &hv_MovementOfObject);
					AffineTransContourXld(ho_vecShapeModel[j], &ho_ModelAtNewPosition, hv_MovementOfObject);
					/*if (HDevWindowStack::IsOpen())
					SetColor(HDevWindowStack::GetActive(), "cyan");
					if (HDevWindowStack::IsOpen())
					DispObj(ho_ModelAtNewPosition, HDevWindowStack::GetActive());*/
					if (HDevWindowStack::IsOpen())
						SetColor(HDevWindowStack::GetActive(), "blue");
					AffineTransPixel(hv_MovementOfObject, -120, 0, &hv_RowArrowHead, &hv_ColumnArrowHead);
					DispArrow(hv_WindowHandle, HTuple(hv_RowCheck[hv_j]), HTuple(hv_ColumnCheck[hv_j]),
						hv_RowArrowHead, hv_ColumnArrowHead, 2);
				}
			}
			disp_continue_message(hv_WindowHandle, "black", "true");
			if (hv_Score.Length() > 0)
			{
				cout << "The current ID is :" << i << endl;
				cout << "The current Coordinate is:(" << hv_RowCheck[0].D() << "," << hv_Column[0].D() << ")" << endl;
				cout << "The angle is:" << hv_AngleCheck[0].D() * 180 / PI << endl;
				cout << "The similiarity value is :" << hv_Score[0].D() << endl;

				CloseFramegrabber(hv_tmpFGHandle);

			}
			//	Sleep(2000);
		}
		// stop(...); only in hdevelop
	}
	cout << "The time is:" << clock() - t << "ms" << endl;

	//-------------------  end of the application  -----------------
	//clean up
	// dev_update_window(...); only in hdevelop
	ClearShapeModel(hv_ModelID);
	CloseFramegrabber(hv_FGHandle);
}



#ifdef __APPLE__
// On OS X systems, we must have a CFRunLoop running on the main thread in
// order for the HALCON graphics operators to work correctly, and run the
// action function in a separate thread. A CFRunLoopTimer is used to make sure
// the action function is not called before the CFRunLoop is running.
// Note that starting with macOS 10.12, the run loop may be stopped when a
// window is closed, so we need to put the call to CFRunLoopRun() into a loop
// of its own.
HTuple      gStartMutex;
H_pthread_t gActionThread;
HBOOL       gTerminate = FALSE;

static void timer_callback(CFRunLoopTimerRef timer, void *info)
{
	UnlockMutex(gStartMutex);
}

static Herror apple_action(void **parameters)
{
	// Wait until the timer has fired to start processing.
	LockMutex(gStartMutex);
	UnlockMutex(gStartMutex);

	action();

	// Tell the main thread to terminate itself.
	LockMutex(gStartMutex);
	gTerminate = TRUE;
	UnlockMutex(gStartMutex);
	CFRunLoopStop(CFRunLoopGetMain());
	return H_MSG_OK;
}

static int apple_main(int argc, char *argv[])
{
	Herror                error;
	CFRunLoopTimerRef     Timer;
	CFRunLoopTimerContext TimerContext = { 0, 0, 0, 0, 0 };

	CreateMutex("type", "sleep", &gStartMutex);
	LockMutex(gStartMutex);

	error = HpThreadHandleAlloc(&gActionThread);
	if (H_MSG_OK != error)
	{
		fprintf(stderr, "HpThreadHandleAlloc failed: %d\n", error);
		exit(1);
	}

	error = HpThreadCreate(gActionThread, 0, apple_action);
	if (H_MSG_OK != error)
	{
		fprintf(stderr, "HpThreadCreate failed: %d\n", error);
		exit(1);
	}

	Timer = CFRunLoopTimerCreate(kCFAllocatorDefault,
		CFAbsoluteTimeGetCurrent(), 0, 0, 0,
		timer_callback, &TimerContext);
	if (!Timer)
	{
		fprintf(stderr, "CFRunLoopTimerCreate failed\n");
		exit(1);
	}
	CFRunLoopAddTimer(CFRunLoopGetCurrent(), Timer, kCFRunLoopCommonModes);

	for (;;)
	{
		HBOOL terminate;

		CFRunLoopRun();

		LockMutex(gStartMutex);
		terminate = gTerminate;
		UnlockMutex(gStartMutex);

		if (terminate)
			break;
	}

	CFRunLoopRemoveTimer(CFRunLoopGetCurrent(), Timer, kCFRunLoopCommonModes);
	CFRelease(Timer);

	error = HpThreadHandleFree(gActionThread);
	if (H_MSG_OK != error)
	{
		fprintf(stderr, "HpThreadHandleFree failed: %d\n", error);
		exit(1);
	}

	ClearMutex(gStartMutex);
	return 0;
}
#endif