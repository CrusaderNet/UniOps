#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
    private:
        int counter;
        int limit;
        static int nCounters;

    public:
        Counter(int arg1, int arg2)
        {counter = arg1; limit = arg2; nCounters++;}

        void increment()
        {
            if(counter < limit)
                counter++;
        }

        void decrement()
        {
            if(counter > 0)
                counter--;
        }

};
int Counter::nCounters = 0;

#endif
