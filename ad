[1mdiff --git a/Calculator/Calculator.vcxproj b/Calculator/Calculator.vcxproj[m
[1mindex abd90cc..b146ce6 100644[m
[1m--- a/Calculator/Calculator.vcxproj[m
[1m+++ b/Calculator/Calculator.vcxproj[m
[36m@@ -139,8 +139,14 @@[m
     </Link>[m
   </ItemDefinitionGroup>[m
   <ItemGroup>[m
[32m+[m[32m    <ClCompile Include="HeaderDetails.cpp" />[m
[32m+[m[32m    <ClCompile Include="IOHandler.cpp" />[m
     <ClCompile Include="Source.cpp" />[m
   </ItemGroup>[m
[32m+[m[32m  <ItemGroup>[m
[32m+[m[32m    <ClInclude Include="Header.h" />[m
[32m+[m[32m    <ClInclude Include="IOHandler.h" />[m
[32m+[m[32m  </ItemGroup>[m
   <Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />[m
   <ImportGroup Label="ExtensionTargets">[m
   </ImportGroup>[m
[1mdiff --git a/Calculator/Calculator.vcxproj.filters b/Calculator/Calculator.vcxproj.filters[m
[1mindex 65473da..9748ef3 100644[m
[1m--- a/Calculator/Calculator.vcxproj.filters[m
[1m+++ b/Calculator/Calculator.vcxproj.filters[m
[36m@@ -18,5 +18,19 @@[m
     <ClCompile Include="Source.cpp">[m
       <Filter>Source Files</Filter>[m
     </ClCompile>[m
[32m+[m[32m    <ClCompile Include="HeaderDetails.cpp">[m
[32m+[m[32m      <Filter>Source Files</Filter>[m
[32m+[m[32m    </ClCompile>[m
[32m+[m[32m    <ClCompile Include="IOHandler.cpp">[m
[32m+[m[32m      <Filter>Source Files</Filter>[m
[32m+[m[32m    </ClCompile>[m
[32m+[m[32m  </ItemGroup>[m
[32m+[m[32m  <ItemGroup>[m
[32m+[m[32m    <ClInclude Include="Header.h">[m
[32m+[m[32m      <Filter>Source Files</Filter>[m
[32m+[m[32m    </ClInclude>[m
[32m+[m[32m    <ClInclude Include="IOHandler.h">[m
[32m+[m[32m      <Filter>Header Files</Filter>[m
[32m+[m[32m    </ClInclude>[m
   </ItemGroup>[m
 </Project>[m
\ No newline at end of file[m
[1mdiff --git a/Calculator/Source.cpp b/Calculator/Source.cpp[m
[1mindex 946be02..6bfe9d0 100644[m
[1m--- a/Calculator/Source.cpp[m
[1m+++ b/Calculator/Source.cpp[m
[36m@@ -1,6 +1,4 @@[m
 #include <iostream>[m
[31m-#include <string>[m
[31m-#include <stack>[m
 [m
 #define F(i,a,b) for (int i=a; i<=b; i++)[m
 [m
[36m@@ -8,227 +6,21 @@[m [musing namespace std;[m
 [m
 const int MAX = 100;[m
 [m
[31m-struct DataStored[m
[31m-{[m
[31m-	char Name[11];[m
[31m-	float Data;[m
[31m-};[m
[31m-[m
[31m-DataStored VariableDataStored[MAX + 1];[m
[31m-[m
[31m-bool isDigit(char x)[m
[31m-{[m
[31m-	return (x >= '0' && x <= '9');[m
[31m-}[m
[31m-[m
[31m-bool isOperator(char x)[m
[31m-{[m
[31m-	return (x == '+' || x == '-' || x == '*' || x == '/');[m
[31m-}[m
[31m-[m
[31m-int Prioritize(char x)[m
[31m-{[m
[31m-	if (x == '(') return 0;[m
[31m-	else[m
[31m-		if (x == '+' || x == '-') return 1;[m
[31m-		else[m
[31m-			if (x == '*' || x == '/') return 2;[m
[31m-[m
[31m-	return -1;[m
[31m-}[m
[31m-[m
[31m-void InfixToPostfix(char infix[], char postfix[])[m
[31m-{[m
[31m-	int j = 0;[m
[31m-	stack <char> Operator;[m
[31m-[m
[31m-	bool minus[MAX + 1];[m
[31m-	memset(minus, false, sizeof(minus));[m
[31m-	int nInfix = strlen(infix);[m
[31m-[m
[31m-	// Change minus to plus instead[m
[31m-	/*for (int i = 0; infix[i] != '\0'; i++)[m
[31m-		if (infix[i] == '-')[m
[31m-		{[m
[31m-			infix[i] = '+';[m
[31m-			int j = i;[m
[31m-			while (!isDigit(infix[j]) && infix[j + 1] != '\0') j++;[m
[31m-[m
[31m-			if (!minus[j]) minus[j] = true;[m
[31m-			else[m
[31m-				minus[j] = false;[m
[31m-		}*/[m
[31m-[m
[31m-	for (int i = 0; i<nInfix; i++)[m
[31m-	{[m
[31m-		if (infix[i] == ' ' || infix[i] == '\t') continue; //remove space in infix array[m
[31m-[m
[31m-		if (isDigit(infix[i]))[m
[31m-		{[m
[31m-			postfix[j++] = infix[i];[m
[31m-			while (isDigit(infix[i + 1]) || infix[i + 1] == '.')[m
[31m-			{[m
[31m-				i++;[m
[31m-				postfix[j++] = infix[i];[m
[31m-			}[m
[31m-			[m
[31m-			postfix[j++] = ' ';[m
[31m-		}[m
[31m-		else[m
[31m-		{[m
[31m-			if (infix[i] == '(') Operator.push(infix[i]);[m
[31m-			else[m
[31m-				if (infix[i] == ')')[m
[31m-				{[m
[31m-					char x = Operator.top();[m
[31m-					Operator.pop();[m
[31m-					while (x != '(')[m
[31m-					{[m
[31m-						postfix[j++] = x;[m
[31m-						x = Operator.top();[m
[31m-						Operator.pop();[m
[31m-					}[m
[31m-				}[m
[31m-				else[m
[31m-				{[m
[31m-					if (!Operator.empty())[m
[31m-					{[m
[31m-						while (Prioritize(infix[i]) <= Prioritize(Operator.top()))[m
[31m-						{[m
[31m-							postfix[j++] = Operator.top();[m
[31m-							Operator.pop();[m
[31m-[m
[31m-							if (Operator.empty()) break;[m
[31m-						}[m
[31m-					}				[m
[31m-					Operator.push(infix[i]);[m
[31m-				}[m
[31m-		}[m
[31m-	}[m
[31m-[m
[31m-	while (!Operator.empty())[m
[31m-	{[m
[31m-		postfix[j++] = Operator.top();[m
[31m-		Operator.pop();[m
[31m-	}[m
[31m-[m
[31m-	postfix[j] = '\0';[m
[31m-[m
[31m-	// Calculate[m
[31m-[m
[31m-	stack <float> Number;[m
[31m-	int nPostfix = strlen(postfix);[m
[31m-	for (int i = 0; i<nPostfix; i++)[m
[31m-	{[m
[31m-		while (postfix[i] == ' ') i++;[m
[31m-[m
[31m-		if (isDigit(postfix[i]))[m
[31m-		{[m
[31m-			float realNumber = 1;[m
[31m-			float num = int(postfix[i]) - 48;[m
[31m-			[m
[31m-			while (isDigit(postfix[i + 1]) || (postfix[i + 1] == '.'))[m
[31m-			{[m
[31m-				i++;[m
[31m-				if (postfix[i] == '.')[m
[31m-				{[m
[31m-					realNumber = 10;[m
[31m-					continue;[m
[31m-				}[m
[31m-				float x = int(postfix[i]) - 48;[m
[31m-[m
[31m-				if (realNumber == 1) num = num * 10 + x;[m
[31m-				else[m
[31m-				{[m
[31m-					num = num + (x / realNumber);[m
[31m-					realNumber = realNumber * 10;[m
[31m-				}[m
[31m-			}[m
[31m-[m
[31m-			Number.push(num);[m
[31m-		}[m
[31m-		else[m
[31m-		{[m
[31m-			float a = Number.top(); Number.pop();[m
[31m-			float b = Number.top(); Number.pop();[m
[31m-			switch (postfix[i])[m
[31m-			{[m
[31m-			case '+':[m
[31m-				Number.push(a + b);[m
[31m-				break;[m
[31m-			case '-':[m
[31m-				Number.push(b - a);[m
[31m-				break;[m
[31m-			case '*':[m
[31m-				Number.push(a * b);[m
[31m-				break;[m
[31m-			case '/':[m
[31m-				Number.push(b / a);[m
[31m-			}[m
[31m-		}[m
[31m-	}[m
[31m-[m
[31m-	float result = Number.top();[m
[31m-	cout << "Result is: " << result;[m
[31m-}[m
[31m-[m
[31m-void basicCalculator()[m
[31m-{[m
[31m-	bool checkRightExpression = false;[m
[31m-	char Expression[MAX + 1], postfixExpression[MAX + 1];[m
[31m-[m
[31m-	cout << "\nWrite your calculation: ";[m
[31m-[m
[31m-	cin.ignore();[m
[31m-	gets_s(Expression);[m
[31m-[m
[31m-	// Check that the expression entered is correct or not[m
[31m-[m
[31m-	while (!checkRightExpression)[m
[31m-	{[m
[31m-		int lengthExpression = strlen(Expression);[m
[31m-[m
[31m-		int rightParenthese = 0;[m
[31m-[m
[31m-		F(i, 0, lengthExpression - 1)[m
[31m-		{[m
[31m-			if (Expression[i] == '(') [m
[31m-				rightParenthese++;[m
[31m-			else[m
[31m-			if (Expression[i] == ')')[m
[31m-				rightParenthese--;[m
[31m-[m
[31m-			if (rightParenthese < 0) break;[m
[31m-		}[m
[31m-[m
[31m-		if (rightParenthese != 0 || isOperator(Expression[lengthExpression-1]))[m
[31m-		{[m
[31m-			cout << "Your expression is incorrect, enter again? Y/N: ";[m
[31m-			char question;[m
[31m-			cin >> question;[m
[31m-			if (question == 'N') return;[m
[31m-		}[m
[31m-		else checkRightExpression = true;[m
[31m-[m
[31m-[m
[31m-	}[m
[31m-[m
[31m-	// Process expression using stack and Postfix[m
[31m-	InfixToPostfix(Expression, postfixExpression);[m
[31m-}[m
[32m+[m[32mchar DataStored[300][MAX + 1];[m
[32m+[m[32mint nDatastored = 0;[m
 [m
 void assignVariable()[m
 {[m
[31m-	char Input[MAX + 1], Variable[MAX + 1];[m
[32m+[m	[32mchar Variable;[m
 [m
[32m+[m	[32mcout << "Name of Variable: ";[m
[32m+[m	[32mcin >> Variable;[m
[32m+[m	[32mcout << "\nValue of Variable: ";[m
[32m+[m[41m	[m
 	cin.ignore();[m
[31m-	gets_s(Input);[m
[31m-[m
[31m-	int i;[m
[31m-	for (i = 0; Input[i] != ' '; i++)  Variable[i] = Input[i];[m
[31m-	Variable[++i] = '\0';[m
[31m-[m
[32m+[m	[32mgets_s(DataStored[Variable]);[m
 [m
[32m+[m	[32mcout << "Stored ! \n";[m
 }[m
 [m
 void Menu()[m
[36m@@ -236,21 +28,28 @@[m [mvoid Menu()[m
 	cout << "Choose your option:\n";[m
 	cout << "1: Basic Calculator\n";[m
 	cout << "2: Assign Variable:\n";[m
[32m+[m	[32mcout << "8: EXIT!";[m
 }[m
 [m
[31m-int main()[m
[32m+[m[32mint main1()[m
 {[m
[31m-	Menu();[m
[31m-	int option;[m
[31m-	cin >> option;[m
[31m-[m
[31m-	switch (option)[m
[32m+[m	[32mwhile (true)[m
 	{[m
[31m-	case 1:[m
[31m-		basicCalculator();[m
[31m-		break;[m
[31m-	case 2:[m
[31m-		assignVariable();[m
[31m-		break;[m
[32m+[m		[32mMenu();[m
[32m+[m		[32mint option;[m
[32m+[m		[32mcin >> option;[m
[32m+[m
[32m+[m		[32mswitch (option)[m
[32m+[m		[32m{[m
[32m+[m		[32mcase 1:[m
[32m+[m			[32m//basicCalculator();[m
[32m+[m			[32mbreak;[m
[32m+[m		[32mcase 2:[m
[32m+[m			[32massignVariable();[m
[32m+[m			[32mbreak;[m
[32m+[m		[32mcase 8:[m
[32m+[m			[32mreturn 0;[m
[32m+[m		[32m}[m
 	}[m
[32m+[m[41m	[m
 }[m
\ No newline at end of file[m
