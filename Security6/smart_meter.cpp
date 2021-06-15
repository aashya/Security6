class SmartMeter
{
private:
    float counter;
    void increaseCounter(float usage)
    {
        if (usage > 0)
        {
            this->counter += usage;
        }
    }

public:
    enum period
    {
        Peak,
        OffPeak,
        Normal
    };
    float computeUsage(float *kwMinute, int size, enum period rate)
    {
        float usage = 0;
        for (int i = 0; i < size;
             i++)
        {
            float rating = 1.0;
            if (rate == Peak)
            {
                rating = 2.0;
            }
            else if (rate == OffPeak)
            {
                rating = 0.5;
            }
            usage += kwMinute[i] * rating;
        }
        return usage;
    }
    void meterUsageCycle(float *kwMinute, int size, enum period rate)
    {
        float kwHour = 0;
        kwHour = computeUsage(kwMinute, size, rate);
        this->increaseCounter(kwHour);
    }
    float getCounter()
    {
        return this->counter;
    }
};
