#ifndef PD_MACROS_H_INCLUDED
#define PD_MACROS_H_INCLUDED

#include "../macros.h"

#define LN2INV 1.442695041      /* 1 over natural log of 2 :                    
                                 * * log2(x) = (1/log(2)) * log(x) */ 

#define DELETE_FLAGGED_ENTITIES(entity_array, flag) { \
	Entity2D *e; \
	for (size_t i=entity_array.GetCount(); i>0; ) \
		if (entity_array[--i]->GetFlag(flag)) { \
			e = entity_array[i]; \
			DELETE_OBJECT(e); \
			entity_array.RemoveAt(i); \
		} \
}



// Following Macros are used to verify processing 

#ifdef _DB_BUILDER
#define MAX_PROCESSING_TIME MAX_PROCESSING_TIME_QUERY_SEC
#else
#define MAX_PROCESSING_TIME MAX_PROCESSING_TIME_BUILD_SEC
#endif

// Following Macros are used by for processing time verification
#define EXCEEDING_PROCESSING_TIME(now, start) \
	((((now)-(start)).GetSeconds()>PolygonDetection::PolygonDetector::GetMaxProcessingTime()) || PolygonDetector::WasInterrupted())

#define SHOW_INTERRUPTED_MESSAGE() if (PolygonDetection::PolygonDetector::WasInterrupted()) {\
	wxLogWarning("%s aborted!\n\t\t%s\n\t\tElapsed time: %u secs.", \
	(__step_msg), \
	PolygonDetection::PolygonDetector::TimeWasExceeded()?"Processing time exceeded pre-specified limit.":"Processing Iterrupted.", \
	(wxDateTime::Now()-start).GetSeconds()); \
	YIELD_CONTROL();\
}

//
// Following macros are used to display messages during processing
//
#define printf(step) \
	const wxString __step_msg(step); \
	wxDateTime start = wxDateTime::UNow(); \
	if (!PolygonDetection::PolygonDetector::Silent())	printf("%s started.", __step_msg); 

#define ENDING_PROCESS_MESSAGE() { \
	SHOW_INTERRUPTED_MESSAGE() \
	if (!PolygonDetection::PolygonDetector::Silent() && !PolygonDetection::PolygonDetector::WasInterrupted()) { \
			wxDateTime end = wxDateTime::UNow(); \
			long time_span = (end-start).GetMilliseconds().ToLong(); \
			bool msecs = true; \
			if (time_span > MSECS2SECS_THRESHOLD) { \
				msecs = false; \
				time_span /= 1000; \
			}\
			printf("%s finished (took %u %s)", __step_msg, time_span, msecs?"ms":"secs"); \
	} \
}

#endif
