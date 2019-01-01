#include<bits/stdc++.h>

using namespace std;

int main()
{
	set<int> s;
	map<int, int> left;
	map<int, int> right;
	int n, root;
	cin >> n;
	vector<int> arr(n + 1, 0);
	for(int i = 1; i <= n; i++)
	{
		int val;
		cin >> val;
		arr[i] = val;
		if(i == 1)
		{
			root = val;
			s.insert(root);
			continue;
		}
		auto it = s.upper_bound(val);
		if(it == s.begin())
		{
			if(left.find(*it) == left.end())
			{
				left[*it] = val;
			}
		}
		else if(it == s.end())
		{
			--it;
			right[*it] = val;
		}
		else
		{
			if(left.find(*it) == left.end())
			{
				left[*it] = val;
			}
			else
			{
				--it;
				right[*it] = val;
			}
		}
		s.insert(val);
	}
	map<int, int> answer;
	for(auto i : left)
	{
		answer[i.second] = i.first;
	}
	for(auto i : right)
	{
		answer[i.second] = i.first;
	}
	for(int i = 1; i <= n; i++)
	{
		if(arr[i] == root)
		{
			continue;
		}
		cout << answer[arr[i]] << ' ';
	}
	return 0;
}

/*
                       :                      :M
                         XMX                   .HMM>
                         MMMM.                dMMMM>
                        'MMMMMX     .....   dMMMMMMX
                        XMMMMMMMnMMMMMMMMMMMMMMMMMMM
                       :MMMMMMMMMMMMMMMMMMMMMMMMMMMM>
                       XMMMMM!"    "MMMMMM"`  `"MMMMM
                       MMMM#         4MMf        `MMMX
                      XMMM            MX          'MMM:
                     'MMM~            '>            MMM
                     MMMf       .     '>            `MMX
                    MMMM>     :MMM    '>   :MMM      MMMX
                   XMMMM      MMMM>   '>   XMMMX     MMMMk
                  MMMMMM>     MMMM~   'k   MMMMX     MMMMMh
                 MMMMMMMX     XMMM    XX   ?MMM     XMMMMMMM
                 MMMMMMMMk     ^`    X 'h    `     :MM##MMM~
                  ?MM>  ^?M.       .!    %.      .HM"   MM
                 .?M      '"%+++!".nMMMMn "%++!*" %.. 'M..
                  `?M>+%L         <MMMMMMMM>       :   XM"
                    'X   %        XMMMMMMMM>      X   'f
                      X   `M.      ?MMMMMM~    .HM   :`
                       %.  `MMMx.          .xHMMM   X
                  ..    `X  `MMMMMMMMMMMMMMMMMMM  :f
                :MMMMMMMh:.M. 4MM     "     MM" xMMMMMMMMMMh.
              :MMMMMMMMMMMMMMM: `%x.......x"`.HMMMMMMMMMMMMMM
            .MMMMMMMMMMMMMMMMMMMMhx.......xHMMMMMMMMMMMMMMMMM
    .nHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM`MMMMMMMMMMMMMMMMX
  :MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMdMMMMMMMMMMMMMMMMMMMM
 MMMMMMMMMMMMMMMMMMMM"``""MMMMMMMMMMMM!MMMMMMMMMMMMMMMMMMMM~
MMMMMMMMMMMMMMMMMMM!     XMMMMMMMMMMMf:HMMMMMMMMMMMMMMMMM!
M?MMMMMMMMMMMMMMMM`    :MMMMMMMMMMMM!MMMMMMMMMMMMMMMMMMM~
:MMMMMMMMMMMMMMMMX     MMMMMMMMMMMMXXMMMMMMMMMMMMMMMMM`
MMMMMMMMMMMMMMMMMX    'MMMMMMMMMMMMM!MMMMMMMMMMMMMMMMX
MMMMMMMMMMMMMMMMM~    'MMMMMMMMMMMMMM?MMMMMMMMMMMMMMM~
 #M)MMMMMMMM!MMM       MMMMMMMMMMMMMMMM/MMMMMMMMMMMM~
   ?MMMMMM"-"2MMMMMx   XMMMMMMMMMMMMMMMMX?**!:MMM"`
     ^""    XMMMMMMMM  'MMMMMMMMMMM"`MMMMMMMMMMM>
           XMMMMMMMMML  MMMMMMMMMX .MMMMMMMMMMMf
           XMMMMMMMMMML 4MMMMMMMMMXMMMMMMMMMMM~
          XMMMMMMMMMMMMXMMMMMMMMMMXMMMMMMMMMx.
            MMMMMMMMMMMMM!MMMMMMMMMMLMMMMMMMMMMMMx
             #MMMMMMMMMMMMMMMMMMMMMMM!MMMMMMMMMMMMM
              `MMMMMMMMMMMLMMMMMMMMMMM/MMMMMMMMMMMM>
                 `*MMMMM!nMMMMMHh(?*MMM?MMMMMMMMMMM>
                       XMMMMMMMMMMMMMMMX4MMMMMMMMMM
                      XM#     `*MMMMMMMMXMMMMMMMM"
                     'M          `MMMMMMMX^"*""
                     Xf            !?MMMMMM
                     'X             X ?MMMMM
                      !             `> `MMMMX
                       #:     4     X>  'MMMM>
                        `L     "x.xM~    `MMMX
                          %.    f         MMMX
                           `#M``         :MMM~
                              `Mx.      dMMM~
                                 ``"**MM*"



*/