extern char * app_name = (char*)("PolygonDetector v0.1 (2008/03/05)");
extern char * app_description = (char*)"Prototype for detecting polygons from a set of lines";
extern char * app_author = (char*)"Alfredo Ferreira";
extern int app_year = 2008;

extern void print_header();
extern void print_gpl();
extern void print_warranty();

#include <stdio.h>
#include <string>

#include "./PolygonDetection/PolygonDetector.h"

void print_help() {
    printf("\nUsage: PolygonDetector [options] <source> <destination>\n\n");
    printf("Options:\n");
    printf("--help,  -h\t: Show Help.\n");
    printf("--gpl, -gpl\t: Print the GNU GPL.\n");
    printf("--quiet, -q\t: Silent algorithm execution.\n");
    printf("--limit <time>\t: Specify the time limit (in secs) for algorithm execution.\n");
    printf("            \t  Default time limit is 240 secs.\n");
    printf("\n");
}

PolygonDetection::PolygonDetector * read_file(const char * filename) {

    if (!filename) {
        fprintf(stderr, "Error: Invalid filename.\n");
        return nullptr;
    }

    PolygonDetection::PolygonDetector * polygon_detector = nullptr;

    return polygon_detector;
}

bool process(int argc, char* argv[]) {
    bool verbose=true;
    bool show_stats=false;
    int time_limit = 0;

    std::string src = "";
    std::string dest = "";

    // Parse arguments
    argc--; argv++;
    while (argc > 0) {
        if ((*argv)[0] == '-') {
            if ((strcmp(*argv, "-h")==0) || (strcmp(*argv, "--help")==0)) {
                print_help();
                return true;
            }
            else
                if ((strcmp(*argv, "-gpl")==0) || (strcmp(*argv, "--gpl")==0)) {
                    print_gpl();
                    return true;
                }
                if (strcmp(*argv, "--warranty")==0) {
                    print_warranty();
                    return true;
                }
                else
                    if ((strcmp(*argv, "-s")==0) || (strcmp(*argv, "--stats")==0))
                        show_stats = true;
                    else
                        if ((strcmp(*argv, "-q")==0) || (strcmp(*argv, "--quiet")==0))
                            verbose = false;
                            else
                                if (strcmp(*argv,"--limit")==0) {
                                    argc--;argv++;

                                    if (!(argc>0)) return false;

                                    if ((*argv)[0] == '-')
                                        return false;
                                    time_limit = atoi(*argv);
                                    if (time_limit==0) {
                                        fprintf(stderr,"Specified time limit is invalid.\n");
                                        return false;
                                    }
                                } else {
                                    fprintf(stderr, "Error: Invalid program argument: %s", *argv);
                                    print_help();
                                    return false;
                                }
                argv++; argc--;
        }
        else {
            if (src.empty()) src = (*argv);
            else
                if (dest.empty()) dest = (*argv);
                else {
                    fprintf(stderr, "Error: Invalid program argument: %s", *argv);
                    print_help();
                    return false;
                }
            argv++; argc--;
        }
    }

    if (src.empty() || dest.empty()) {
        fprintf(stderr,"Error: Source and destination files must be specified.\n");
        print_help();
        return false;
    }

    // parsed the arguments, now let's read the file
    PolygonDetection::PolygonDetector polygon_detector;

    if (time_limit>0)
        polygon_detector.SetMaxProcessingTime(time_limit);

    if (!verbose)
        polygon_detector.Silent(true);

    if (!polygon_detector.ReadSVGfile(src.c_str()))  {
        fprintf(stderr,"Error: Unable to read line set from SVG file.\n");
        return false;
    }

    // the lines were loaded, lets detect the polygons
    if (!polygon_detector.DetectPolygons() || !polygon_detector.GetPolygonSet()) {
        fprintf(stderr, "Error: Failed to detect the polygons.\n");
        return false;
    }

    //simplify the polygon set
    polygon_detector.SimplifyPolygons(0.0);

    // the polygons were detected, lets save them
    if (!polygon_detector.CreateSVGwithPolygons(dest.c_str())) {
        fprintf(stderr, "Error: Failed to crate the SVG with the polygons.\n");
        return false;
    }

    return true;
}

int main(int argc, char * argv[])
{
    print_header();

    if (!process(argc, argv))
        return 1;

    return 0;
}

