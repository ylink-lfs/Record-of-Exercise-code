 int guessNumber(int n) {
        int mid;
        int lower = 1;
        int upper = n;
        while(lower <= upper)
        {
            mid = lower + (upper - lower) / 2;
            int cache = guess(mid);
            if(guess(mid) == 0)
            {
                return mid;
            }
            else if (guess(mid) == -1)
            {
                upper = mid - 1;
            }
            else
            {
                lower = mid + 1;
            }
        }
        return -1;
    }
