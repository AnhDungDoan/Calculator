#include <iostream>
#include <string>

#define F(i,a,b) for (int i=a; i<=b; i++)

using namespace std;

void basicCalculator()
{
	bool checkRightExpression = false;
	while (!checkRightExpression)
	{
		cout << "\nWrite your calculation: ";

		string Expression;

		cin.ignore();
		getline(cin, Expression);

		int lengthExpression = Expression.size();

		// Check that the expression entered is correct or not
		int rightParenthese = 0;
		F(i, 0, lengthExpression - 1)
		{
			if (Expression[i] == '(')
			{
				rightParenthese++;
			}
			else
			{
				rightParenthese--;
			}

			if (rightParenthese < 0)
			{
				cout << "Your expression is incorrect, enter again? Y/N";
				char question;
				cin >> question;
				if (question == 'N') return;
				break;
			}
		}
	}
}

int main()
{
	cout << "Choose your option:\n";
	cout << "1: Basic Calculator\n";

	int option;
	cin >> option;

	switch (option)
	{
	case 1:
		basicCalculator();
	}
}