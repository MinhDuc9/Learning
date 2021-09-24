#include <iostream>
#include <vector>

using namespace std;

vector<int> lpf; /// lowest prime factor   
vector<int> prime; /// prime list         
vector<int> twinprime; /// twinprime list

int sieve(int n)
{
    lpf.assign(n + 1, 2);
    prime.assign(1, 2);

    for (int x = 3; x <= n; x += 2)
    {
        if (lpf[x] == 2) /// (x) isnt multiple of any other prime than itself
        {
            lpf[x] = x; /// (x) is prime, its lowest prime factor is itself
			// cout << x << endl;
            prime.push_back(x);

            if (lpf[x - 2] == x - 2) /// (x - 2) is also a prime
			{
				// cout << lpf[x-2] << " ok" << endl;
                twinprime.push_back(x - 2);
			}
        }

        for (int t : prime)
        {
            if (t > lpf[x] || t * x > n)
			{
				// cout << t << endl;
				break;
			}
			// cout << t*x << " " << t << endl;
            lpf[t * x] = t;
			// cout << t*x << " " << t << endl << endl;
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    sieve(n);
    cout << twinprime.size() << '\n';
    for (int p : twinprime)
    {
        cout << 2 << ' ' << p << '\n';
    }

    return 0;
}
