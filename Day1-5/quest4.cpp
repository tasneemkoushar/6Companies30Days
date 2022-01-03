/*
    Run Length Encoding
*/
string encode(string src)
{     
  string ans;
  int cnt = 0;
  char c = src[0];
  for(int i=0; src[i]; i++)
  {
      if(src[i]==c)
      {
          cnt++;
      }
      else{
          ans+=c;
          ans+=to_string(cnt);
          cnt = 1;
          c = src[i];
      }
  }
  ans+=c;
  ans+=to_string(cnt);
  return ans;
}     