#include "stats.h"
struct Stats
{
    float average;
    float min;
    float max;
};
struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    double sum = 0.0;

    for (int i = 0; i < setlength - 1; i++)
    {
        sum += numberset[i];
    }
    s.average = sum / setlength;

    if (setlength == 1)
    {
        s.max = numberset[0];
        s.min = numberset[0];
    }
    if (numberset[0] > numberset[1])
    {
        s.max = numberset[0];
        s.min = numberset[1];
    }
    else
    {
        s.max = numberset[1];
        s.min = numberset[0];
    }
    for (int i = 2; i < setlength; i++)
    {
        if (numberset[i] > s.max)
            s.max = numberset[i];
        else if (numberset[i] < s.min)
            s.min = numberset[i];
    }
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
