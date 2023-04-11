#include<bits/stdc++.h>

using namespace std;

char lan[1000][1000] = {0};
bool visited[1000][1000] = {0};

void DFS( int, int );

int main(){
  int N, H, W, maxarea;
  while( scanf( "%d", &N ) != EOF ){
    for( int i = 1 ; i <= N ; i++ ){
      scanf( "%d%d", &H, &W );
      getchar();
      memset( visited, 0, sizeof(visited) );
      int letters[30] = {0};
      maxarea = 0;
      for( int j = 1 ; j <= H ; j++ ){
        for( int k = 1 ; k <= W ; k++ )
          scanf( "%c", &lan[j][k] );
        getchar();
      }
      for( int j = 1 ; j <= H ; j++ )
        for( int k = 1 ; k <= W ; k++ ){
          if( !visited[j][k] ){
            maxarea = max( ++letters[lan[j][k]-'a'], maxarea );
            DFS( j, k );
          }
        }
      printf( "World #%d\n", i );
      for( int j = maxarea ; j >= 1 ; j-- )
        for( int k = 0 ; k < 26 ; k++ )
          if( letters[k] == j )
            printf( "%c: %d\n", 'a'+k, j );
    }
  }
  return 0;
}

void DFS( int x, int y ){
  visited[x][y] = 1;
  if( lan[x+1][y] == lan[x][y] && !visited[x+1][y] ) DFS(x+1,y);
  if( lan[x-1][y] == lan[x][y] && !visited[x-1][y] ) DFS(x-1,y);
  if( lan[x][y+1] == lan[x][y] && !visited[x][y+1] ) DFS(x,y+1);
  if( lan[x][y-1] == lan[x][y] && !visited[x][y-1] ) DFS(x,y-1);
}
