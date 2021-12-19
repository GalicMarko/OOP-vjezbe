#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class timer
{
	public:
		int h, m;
		double s;
	
		void timer_output();

		timer()
		{
			h = 1;
			m = 15;
			s = 35;
		}

		timer(int hours, int minutes, double seconds)
		{
			h = hours;
			m = minutes;
			s = seconds;
		}
	
		timer operator + (timer const &t)
		{
			timer r;

			r.h = h + t.h;
			r.m = m + t.m;
			r.s = s + t.s;

			return r;
		}

		timer operator - (timer const &t)
		{
			timer r;

			r.h = h - t.h;
			r.m = m - t.m;
			r.s = s - t.s;

			return r;
		}

		timer operator += (timer const &t)
		{
			timer r;

			r.h += t.h;
			r.m += t.m;
			r.s += t.s;

			return r;
		}

		timer operator -= (timer const &t)
		{
			timer r;

			r.h -= t.h;
			r.m -= t.m;
			r.s -= t.s;

			return r;
		}

		timer operator / (timer const &t)
		{
			timer r;

			r.h = h / t.h;
			r.m = m / t.m;
			r.s = s / t.s;

			return r;
		}

		timer operator /= (timer const &t)
		{
			timer r;

			r.h /= t.h;
			r.m /= t.m;
			r.s /=
				t.s;

			return r;
		}

		timer operator < (timer const &t)
		{
			timer r;

			double sum_r = r.h * 3600 + r.m * 60 + r.s;
			double sum_t = t.h * 3600 + t.m * 60 + t.s;

			if (sum_r <= sum_t)
				return r;
			else
				return t;
		}

		friend ostream& operator << (ostream& os, timer const &t)
		{
			os << t.h << ":" << t.m << ":" << t.s << endl;
			return os;
		}

		operator double()
		{
			double sum = 3600 * h + 60 * m + s;
			
			return sum;
		}
};

/*class TimePenalty
{
public:
	double extraSeconds;

	void penalty(timer &t);

	TimePenalty()
	{
		extraSeconds = 10;
	}

	TimePenalty(double s)
	{
		s = extraSeconds;
	}
};

void TimePenalty::penalty(timer &t)
{
	t.s = t.s + extraSeconds;
	cout << t.s << endl;
}*/

void timer::timer_output()
{
	cout << h << ":" << m << ":" << s << endl;
}

void penalty(timer &t, double m)
{
	t.s = t.s + m;
}

double average_time(timer* arrayOfTimers)
{
	int n = 3;
	double sumTotal = 0;
	
	for (int i = 0; i < n; ++i)
	{
		sumTotal += 3600 * arrayOfTimers[i].h + 60 * arrayOfTimers[i].m + arrayOfTimers[i].s;
	}

	return sumTotal / n;
}

double time_difference(timer t1, double t2)
{
	double difference;
	double sumFirst = 3600 * t1.h + 60 * t1.m + t1.s;

	if (sumFirst >= t2)
		difference = sumFirst - t2;
	else
		difference = t2 - sumFirst;

	return difference;
}

double fastest_time(timer* arrayOfTimers)
{
	int n = 3;
	double fastest = arrayOfTimers[0].h * 3600 + arrayOfTimers[0].m * 60 + arrayOfTimers[0].s;

	for (int i = 0; i < n; ++i)
	{
		double sumOfElement = arrayOfTimers[i].h * 3600 + arrayOfTimers[i].m * 60 + arrayOfTimers[i].s;

		if (sumOfElement <= fastest)
			fastest = sumOfElement;
	}

	return fastest;
}


int main()
{
	timer t1(1, 20, 5), t2(1, 17, 8), t3(1, 9, 28);
	timer arrayOfTimers[] = {t1, t2, t3};
	
	cout << "Average time: " << average_time(arrayOfTimers) << "s." << endl;

	double fastest = fastest_time(arrayOfTimers);

	cout << "Fastest time: " << fastest << "s." << endl;
	cout << "Difference in time: " << time_difference(t1, fastest) << "s." << endl; 

	int m;

	cout << "Input penalty: ";
	cin >> m;

	penalty(t3, m);
	t3.timer_output();
}