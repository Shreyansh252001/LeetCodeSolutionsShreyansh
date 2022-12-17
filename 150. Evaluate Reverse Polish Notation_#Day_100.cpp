   unordered_map<string, function<int (long int, long int) > > map = {
            { "+" , [] (long int a, long int b) { return a + b; } },
            { "-" , [] (long int a, long int b) { return a - b; } },
            { "*" , [] (long int a, long int b) { return a * b; } },
            { "/" , [] (long int a, long int b) { return a / b; } }
        };
      
        std::stack<long int> stack;
      
        for (string&s : tokens) 
        {
            if (!map.count(s)) {
                stack.push(stoi(s));
            } else {
                int op1 = stack.top();
                stack.pop();
                int op2 = stack.top();
                stack.pop();
                stack.push(map[s](op2, op1));
            }
        }
