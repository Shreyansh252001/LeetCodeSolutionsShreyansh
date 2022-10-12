  int count = 0;
      for(int i = 0; i <= N; i++) {
        String s = String.valueOf(i);
        if(s.contains("3")) continue;
        if(s.contains("4")) continue;
        if(s.contains("7")) continue;
        
        if(s.contains("2") || s.contains("5") || s.contains("6") || s.contains("9")) count++;
        
      }
      return count;
