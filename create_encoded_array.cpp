#include <iostream>
#include <math.h>
#define STEP 9

using namespace std;

bool is_legal_comb(uint32_t pos_number)
{
    // convert to STEP-base number and is number of zero ('$') exceeds 1 return false
    bool one_dollar = false;
    //std::string converted_number;
    uint8_t nb_of_places = 0;
    while (pos_number > 0)
    {
        ++nb_of_places;
        if (!(pos_number % 5)) // a '$' sign is detected
        {
            if (one_dollar)
            {
                return false;
            }
            else
                one_dollar = true;
        }
        pos_number /= 5;
    }
    if (nb_of_places <= STEP - 2 || (nb_of_places <= STEP - 1 && one_dollar))
    {
        return false;
    }

    return true;
}

int main()
{
    const uint32_t TOTAL_COMB_CNT = (1 + STEP / 4) * pow(4, STEP);
    const uint32_t ALL_POSS_COMB_CNT = (uint32_t)pow(5, STEP);
    // '0' instead of '-1' is used for illegal combinations
    int *EncodedArray = new int[ALL_POSS_COMB_CNT - 1];
    // build encoded array
    {
        uint32_t current_comb_count = 0;
        uint32_t legal_count = 0;
        for (uint32_t i = 0; i < ALL_POSS_COMB_CNT; ++i)
        {
            if (is_legal_comb(i))
            {
                ++legal_count;
                EncodedArray[i] = current_comb_count;
                ++current_comb_count;
            }
            else
            {
                EncodedArray[i] = -1;
            }
        }
    }
    cout << "{";
    for (size_t i = 0; i < ALL_POSS_COMB_CNT; ++i)
    {
        cout << EncodedArray[i] << ", ";
    }
    cout << "}" << endl;
    return 0;
}

#undef STEP
