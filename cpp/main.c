#include <stdio.h>  
#include <stdlib.h>  
#include "map.h" 

#define STARTNODE   1  
#define pathway0    2
#define pathway1    3
#define pathway2    4
#define pathway3    5
#define pathway4    6
#define pathway5    7
#define pathway6    8
#define pathway7    10
#define pathway8    11

//#define ENDNODE     8 
#define BARRIER     9  


typedef struct AStarNode  
{  
    int s_x;    // 坐标(最终输出路径需要)  
    int s_y;  
    int s_g;    // 起点到此点的距离( 由g和h可以得到f，此处f省略，f=g+h )  
    int s_h;    // 启发函数预测的此点到终点的距离  
    int s_style;// 结点类型：起始点，终点，障碍物  
    struct AStarNode * s_parent;    // 父节点  
    int s_is_in_closetable;     // 是否在close表中  
    int s_is_in_opentable;      // 是否在open表中  
}AStarNode, *pAStarNode;  
  
AStarNode  map_maze[x_lenth][y_lenth];        // 结点数组  
pAStarNode open_table[x_lenth*y_lenth+1000];     // open表  
pAStarNode close_table[x_lenth*y_lenth+1000];        // close表  
int  open_node_count; // open表中节点数量  
int    close_node_count;   // close表中结点数量  
pAStarNode path_stack[x_lenth*y_lenth];     // 保存路径的栈  

long int        top = -1;            // 栈顶  int

stateenum workstate=beginstate;
 int Astar_function();  
// 交换两个元素  
//   
void swap( int idx1, int idx2 )    
{    
    pAStarNode tmp = open_table[idx1];  
    open_table[idx1] = open_table[idx2];  
    open_table[idx2] = tmp;  
}    
  
// 堆调整  
//   
void adjust_heap( int /*i*/nIndex )      
{     
    int curr = nIndex;  
    int child = curr * 2 + 1;   // 得到左孩子idx( 下标从0开始，所有做孩子是curr*2+1 )  
    int parent = ( curr - 1 ) / 2;  // 得到双亲idx  
  
    if (nIndex < 0 || nIndex >= open_node_count)  
    {  
        return;  
    }  
      
    // 往下调整( 要比较左右孩子和cuur parent )  
    //   
    while ( child < open_node_count )  
    {  
        // 小根堆是双亲值小于孩子值  
        //   
        if ( child + 1 < open_node_count && open_table[child]->s_g + open_table[child]->s_h  > open_table[child+1]->s_g + open_table[child+1]->s_h )  
        {  
            ++child;// 判断左右孩子大小  
        }  
          
        if (open_table[curr]->s_g + open_table[curr]->s_h <= open_table[child]->s_g + open_table[child]->s_h)  
        {  
            break;  
        }  
        else  
        {  
            swap( child, curr );            // 交换节点  
            curr = child;               // 再判断当前孩子节点  
            child = curr * 2 + 1;           // 再判断左孩子  
        }  
    }  
      
    if (curr != nIndex)  
    {  
        return;  
    }  
  
    // 往上调整( 只需要比较cuur child和parent )  
    //   
    while (curr != 0)  
    {  
        if (open_table[curr]->s_g + open_table[curr]->s_h >= open_table[parent]->s_g + open_table[parent]->s_h)  
        {  
            break;  
        }  
        else  
        {  
            swap( curr, parent );  
            curr = parent;  
            parent = (curr-1)/2;  
        }  
    }  
}    
  
// 判断邻居点是否可以进入open表  
//   
void insert_to_opentable( int x, int y, pAStarNode curr_node, pAStarNode end_node, int w )  
{  
    int i;  
  
    if ( map_maze[x][y].s_style != BARRIER )        // 不是障碍物  
    {  
        if ( !map_maze[x][y].s_is_in_closetable )   // 不在闭表中  
        {  
            if ( map_maze[x][y].s_is_in_opentable ) // 在open表中  
            {  
                // 需要判断是否是一条更优化的路径  
                //   
                if ( map_maze[x][y].s_g > curr_node->s_g + w )    // 如果更优化  
                {  
                    map_maze[x][y].s_g = curr_node->s_g + w;  
                    map_maze[x][y].s_parent = curr_node;  
  
                    for ( i = 0; i < open_node_count; ++i )  
                    {  
                        if ( open_table[i]->s_x == map_maze[x][y].s_x && open_table[i]->s_y == map_maze[x][y].s_y )  
                        {  
                            break;  
                        }  
                    }  
  
                    adjust_heap( i );                   // 下面调整点  
                }  
            }  
            else                                    // 不在open中  
            {  
                map_maze[x][y].s_g = curr_node->s_g + w;  
                map_maze[x][y].s_h = abs(end_node->s_x - x ) + abs(end_node->s_y - y);  
                map_maze[x][y].s_parent = curr_node;  
                map_maze[x][y].s_is_in_opentable = 1;  
                open_table[open_node_count++] = &(map_maze[x][y]);  
            }  
        }  
    }  
}  
  
// 查找邻居  
// 对上下左右8个邻居进行查找  
//    
void get_neighbors( pAStarNode curr_node, pAStarNode end_node )  
{  
    int x = curr_node->s_x;  
    int y = curr_node->s_y;  
  
    // 下面对于8个邻居进行处理！  
    //   
    if ( ( x + 1 ) >= 0 && ( x + 1 ) < x_lenth && y >= 0 && y < y_lenth )  
    {  
        insert_to_opentable( x+1, y, curr_node, end_node, 10 );  
    }  
  
    if ( ( x - 1 ) >= 0 && ( x - 1 ) < x_lenth && y >= 0 && y < y_lenth )  
    {  
        insert_to_opentable( x-1, y, curr_node, end_node, 10 );  
    }  
  
    if ( x >= 0 && x < x_lenth && ( y + 1 ) >= 0 && ( y + 1 ) < y_lenth )  
    {  
        insert_to_opentable( x, y+1, curr_node, end_node, 10 );  
    }  
  
    if ( x >= 0 && x < x_lenth && ( y - 1 ) >= 0 && ( y - 1 ) < y_lenth )  
    {  
        insert_to_opentable( x, y-1, curr_node, end_node, 10 );  
    }  
  
    if ( ( x + 1 ) >= 0 && ( x + 1 ) < x_lenth && ( y + 1 ) >= 0 && ( y + 1 ) < y_lenth )  
    {  
        insert_to_opentable( x+1, y+1, curr_node, end_node, 14 );  
    }  
  
    if ( ( x + 1 ) >= 0 && ( x + 1 ) < x_lenth && ( y - 1 ) >= 0 && ( y - 1 ) < y_lenth )  
    {  
        insert_to_opentable( x+1, y-1, curr_node, end_node, 14 );  
    }  
  
    if ( ( x - 1 ) >= 0 && ( x - 1 ) < x_lenth && ( y + 1 ) >= 0 && ( y + 1 ) < y_lenth )  
    {  
        insert_to_opentable( x-1, y+1, curr_node, end_node, 14 );  
    }  
  
    if ( ( x - 1 ) >= 0 && ( x - 1 ) < x_lenth && ( y - 1 ) >= 0 && ( y - 1 ) < y_lenth )  
    {  
        insert_to_opentable( x-1, y-1, curr_node, end_node, 14 );  
    }  
}  
 int node_x[10];
 int node_y[10];
 static int x_static[];

 int node_setingfunc(int *x,int *y,int size)
 {
	 for(int i = 0;i<size;i++){
		 node_x[i] = x[i];
		 node_y[i] = y[i];
		 
	 }
 } 
 int Astar_function();  ///int main()  
 int Astar_function()  ///int main()
{   
	FILE *fp;
    // 地图数组的定义  
    //   
    AStarNode *start_node;          // 起始点  
    AStarNode *end_node;            // 结束点 
    AStarNode *curr_node;           // 当前点  
    int       is_found;         // 是否找到路径  
    int       pathway_num=0,wholepath_num=0;      //统计路径长度  初始点
/*    int maze[][10] ={           // 仅仅为了好赋值给map_maze  
                        { 1,0,0,3,0,3,0,0,0,0 },  
                        { 0,0,3,0,0,3,0,3,0,3 },  
                        { 3,0,0,0,0,3,3,3,0,3 },  
                        { 3,0,3,0,0,0,0,0,0,3 },  
                        { 3,0,0,0,0,3,0,0,0,3 },  
                        { 3,0,0,3,0,0,0,3,0,3 },  
                        { 3,0,0,0,0,3,3,0,0,0 },  
                        { 0,0,0,0,0,0,0,0,0,0 },  
                        { 3,3,3,0,0,3,2,3,0,3 },  
                        { 3,0,0,0,0,3,3,3,0,3 },  
                    };
*/
    int       i,j,x;
	int       looptime;
	AStarNode save_path[x_lenth*y_lenth]={0};
	int pointarry[10][2]={0};//接收四个坐标
	//int save_path_x[1000]={0},save_path_y[1000]={0};
	save_path[0].s_g = 0;  
    save_path[0].s_h = 0;  
    save_path[0].s_is_in_closetable = 0;  
    save_path[0].s_is_in_opentable = 0;  
    save_path[0].s_style = 0;  
    save_path[0].s_x = 0;  
    save_path[0].s_y = 0;  
    save_path[0].s_parent = NULL;
	fp= fopen("data.txt","w");
	//printf("请按顺序输入点坐标,0<x<92,0<y<176\n");
	//for(i=0;i<4;i++)
	//	for(j=0;j<2;j++)
	//		scanf("%d",&pointarry[i][j]);
	//输入二维码点到地图中
	////点的坐标
	if(node_x[0]==NULL&&node_y[0]==NULL)
	{
		pointarry[0][0]=7;//y
		pointarry[0][1]=11;//x
		pointarry[1][0]=7;
		pointarry[1][1]=15;
		pointarry[2][0]=10;
		pointarry[2][1]=17;
		pointarry[3][0]=7;
		pointarry[3][1]=20;
		pointarry[4][0]=5;
		pointarry[4][1]=23;
		pointarry[5][0]=15;
		pointarry[5][1]=29;
		pointarry[6][0]=18;
		pointarry[6][1]=27;
		pointarry[7][0]=19;
		pointarry[7][1]=23;
		pointarry[8][0]=18;
		pointarry[8][1]=31;
		pointarry[9][0]=18;
		pointarry[9][1]=36;
	}
	else
	{
		pointarry[0][1]=node_x[0];//x
		pointarry[1][1]=node_x[1];
		pointarry[2][1]=node_x[2];
		pointarry[3][1]=node_x[3];
		pointarry[4][1]=node_x[4];
		pointarry[5][1]=node_x[5];
		pointarry[6][1]=node_x[6];
		pointarry[7][1]=node_x[7];
		pointarry[8][1]=node_x[8];
		pointarry[9][1]=node_x[9];
		pointarry[0][0]=node_y[0];//y	
		pointarry[1][0]=node_y[1];	
		pointarry[2][0]=node_y[2];
		pointarry[3][0]=node_y[3];	
		pointarry[4][0]=node_y[4];
		pointarry[5][0]=node_y[5];
		pointarry[6][0]=node_y[6];	
		pointarry[7][0]=node_y[7];	
		pointarry[8][0]=node_y[8];	
		pointarry[9][0]=node_y[9];
	}
	////点的数值
	maze[pointarry[0][1]][pointarry[0][0]]=STARTNODE;
	maze[pointarry[1][1]][pointarry[1][0]]=pathway0;
	maze[pointarry[2][1]][pointarry[2][0]]=pathway1;
	maze[pointarry[3][1]][pointarry[3][0]]=pathway2;
	maze[pointarry[4][1]][pointarry[4][0]]=pathway3;
	maze[pointarry[5][1]][pointarry[5][0]]=pathway4;
	maze[pointarry[6][1]][pointarry[6][0]]=pathway5;
	maze[pointarry[7][1]][pointarry[7][0]]=pathway6;
	maze[pointarry[8][1]][pointarry[8][0]]=pathway7;
	maze[pointarry[9][1]][pointarry[9][0]]=pathway8;
	FILE *fp_erweima = fopen("erweima.txt","wt");
	if(fp_erweima){
		fprintf(fp_erweima,"%d,%d\n", pointarry[0][1], pointarry[0][0]);
		fprintf(fp_erweima,"%d,%d\n", pointarry[1][1], pointarry[1][0]);
		fprintf(fp_erweima,"%d,%d\n", pointarry[2][1], pointarry[2][0]);
		fprintf(fp_erweima,"%d,%d\n", pointarry[3][1], pointarry[3][0]);
		fprintf(fp_erweima,"%d,%d\n", pointarry[4][1], pointarry[4][0]);
		fprintf(fp_erweima,"%d,%d\n", pointarry[5][1], pointarry[5][0]);
		fprintf(fp_erweima,"%d,%d\n", pointarry[6][1], pointarry[6][0]);
		fprintf(fp_erweima,"%d,%d\n", pointarry[7][1], pointarry[7][0]);
		fprintf(fp_erweima,"%d,%d\n", pointarry[8][1], pointarry[8][0]);
		fprintf(fp_erweima,"%d,%d\n", pointarry[9][1], pointarry[9][0]);
	}else{
		puts("warning, open failed");
	}
	fclose(fp_erweima);
	for(looptime=0;looptime<9;looptime++)
	{
	    // 下面准备点  
	    //   
	    for( i = 0; i < x_lenth; ++i )  
	    {  
	        for ( j = 0; j < y_lenth; ++j )  
	        {  
	            map_maze[i][j].s_g = 0;  
	            map_maze[i][j].s_h = 0;  
	            map_maze[i][j].s_is_in_closetable = 0;  
	            map_maze[i][j].s_is_in_opentable = 0;  
	            map_maze[i][j].s_style = maze[i][j];  
	            map_maze[i][j].s_x = i;  
	            map_maze[i][j].s_y = j;  
	            map_maze[i][j].s_parent = NULL;

	  			if(looptime==0)
  				{
		            if ( map_maze[i][j].s_style == STARTNODE )  // 起点  
		            {  
		                start_node = &(map_maze[i][j]);  
		            }  
		            else if( map_maze[i][j].s_style ==  pathway0 )    // 终点   ENDNODE
		            {  
		                end_node = &(map_maze[i][j]);  
		            }  
  				}
				else if(looptime==1)
				{
					 if ( map_maze[i][j].s_style == pathway0 )  // 起点  
		            {  
		                start_node = &(map_maze[i][j]);  
		            }  
		            else if( map_maze[i][j].s_style ==  pathway1 )    // 终点   ENDNODE
		            {  
		                end_node = &(map_maze[i][j]);  
		            }
				}
				else if(looptime==2)
				{
					 if ( map_maze[i][j].s_style == pathway1 )  // 起点  
		            {  
		                start_node = &(map_maze[i][j]);  
		            }  
		            else if( map_maze[i][j].s_style ==  pathway2 )    // 终点   ENDNODE
		            {  
		                end_node = &(map_maze[i][j]);  
		            }
				}
				else if(looptime==3)
				{
					 if ( map_maze[i][j].s_style == pathway2 )  // 起点  
		            {  
		                start_node = &(map_maze[i][j]);  
		            }  
		            else if( map_maze[i][j].s_style ==  pathway3 )    // 终点   ENDNODE
		            {  
		                end_node = &(map_maze[i][j]);  
		            }
				}
				else if(looptime==4)
				{
					 if ( map_maze[i][j].s_style == pathway3 )  // 起点  
		            {  
		                start_node = &(map_maze[i][j]);  
		            }  
		            else if( map_maze[i][j].s_style ==  pathway4 )    // 终点   ENDNODE
		            {  
		                end_node = &(map_maze[i][j]);  
		            }
				}
				else if(looptime==5)
				{
					 if ( map_maze[i][j].s_style == pathway4 )  // 起点  
		            {  
		                start_node = &(map_maze[i][j]);  
		            }  
		            else if( map_maze[i][j].s_style ==  pathway5 )    // 终点   ENDNODE
		            {  
		                end_node = &(map_maze[i][j]);  
		            }
				}
				else if(looptime==6)
				{
					 if ( map_maze[i][j].s_style == pathway5 )  // 起点  
		            {  
		                start_node = &(map_maze[i][j]);  
		            }  
		            else if( map_maze[i][j].s_style ==  pathway6 )    // 终点   ENDNODE
		            {  
		                end_node = &(map_maze[i][j]);  
		            }
				}
				else if(looptime==7)
				{
					 if ( map_maze[i][j].s_style == pathway6 )  // 起点  
		            {  
		                start_node = &(map_maze[i][j]);  
		            }  
		            else if( map_maze[i][j].s_style ==  pathway7 )    // 终点   ENDNODE
		            {  
		                end_node = &(map_maze[i][j]);  
		            }
				}
				else if(looptime==8)
				{
					 if ( map_maze[i][j].s_style == pathway7 )  // 起点  
		            {  
		                start_node = &(map_maze[i][j]);  
		            }  
		            else if( map_maze[i][j].s_style ==  pathway8 )    // 终点   ENDNODE
		            {  
		                end_node = &(map_maze[i][j]);  
		            }
				}
	           // printf("%d ", maze[i][j]);  
	        }  
	  
	       // printf("\n");  
	    }  
	  
	    // 下面使用A*算法得到路径  
	    //    
	    open_table[open_node_count++] = start_node;         // 起始点加入open表  
	      
	    start_node->s_is_in_opentable = 1;               // 加入open表  
	    start_node->s_g = 0;  
	    start_node->s_h = abs(end_node->s_x - start_node->s_x) + abs(end_node->s_y - start_node->s_y);  
	    start_node->s_parent = NULL;  
	      
	    if ( start_node->s_x == end_node->s_x && start_node->s_y == end_node->s_y )  
	    {  
	        printf("起点==终点！\n");  
	        return 0;  
	    }  
	      
	    is_found = 0;  

		
	    while( 1 )  
	    {  
	        // for test  
	        //   
	/*      for ( x = 0; x < open_node_count; ++x ) 
	        { 
	            printf("(%d,%d):%d   ", open_table[x]->s_x, open_table[x]->s_y, open_table[x]->s_g+open_table[x]->s_h); 
	        } 
	        printf("\n\n"); 
	*/  
	        curr_node = open_table[0];      // open表的第一个点一定是f值最小的点(通过堆排序得到的)  
	        open_table[0] = open_table[--open_node_count];  // 最后一个点放到第一个点，然后进行堆调整  
	        adjust_heap( 0 );               // 调整堆  
	          
	        close_table[close_node_count++] = curr_node;    // 当前点加入close表  
	        curr_node->s_is_in_closetable = 1;       // 已经在close表中了  
	  
	        if ( curr_node->s_x == end_node->s_x && curr_node->s_y == end_node->s_y )// 终点在close中，结束  
	        {  
				{
	       			is_found = 1;  
	       			break;  
				}
				/************/

	        }  
	  		
	        get_neighbors( curr_node, end_node );           // 对邻居的处理  
	  
	        if ( open_node_count == 0 )             // 没有路径到达  
	        {  
	            is_found = 0;  
	            break;  
	        }  
			
	    }  
	  
	    if ( is_found )  
	    {  
	        curr_node = end_node; 
	        while( curr_node )  
	        {  
	            path_stack[++top] = curr_node;  
	            curr_node = curr_node->s_parent; 
				pathway_num++;
	        }  
			//wholepath_num=0;
			pathway_num--;
			do{
				save_path[wholepath_num].s_x=(*path_stack[pathway_num]).s_x;
				save_path[wholepath_num].s_y=(*path_stack[pathway_num]).s_y;
				printf("输出的路径为(%d,%d)-->", save_path[wholepath_num].s_x, save_path[wholepath_num].s_y);
				fprintf(fp,"%d,%d\n", save_path[wholepath_num].s_x, save_path[wholepath_num].s_y);
				wholepath_num++;
			}while(pathway_num--);
			top = -1;
			pathway_num=0;
			open_node_count=0;
			close_node_count=0;
			//if(open_table[0]!=NULL)
			{
			for(i=0;i<(x_lenth*y_lenth+1000);i++)
				memset(&open_table[i],0,sizeof(AStarNode));
				//if(close_table[0]!=NULL)
			for(i=0;i<(x_lenth*y_lenth+1000);i++)
				memset(&close_table[i],0,sizeof(AStarNode));
			}
			/*
	        while( top >= 0 )        // 下面是输出路径看看~  
	        {  
	            if ( top > 0 )  
	            {  
	                printf("(%d,%d)-->", path_stack[top]->s_x, path_stack[top--]->s_y);  
	            }  
	            else  
	            {  
	                //printf("(%d,%d)", path_stack[top]->s_x, path_stack[top--]->s_y);  
	            }  
	        }  
			*/
			
	    }  
	    else  
	    {  
	        printf("么有找到路径");  
	    }  
	  
	    puts("");  
	  
	    //return 0;  
	 }
	fclose(fp);
	//while(1);
} 
// int main()
// {
	
// 	Astar_function();
// }

#if 0
/*
{
//把第一段路径保存起来
while( curr_node )  
{  
    path_stack[++top] = curr_node;  
    curr_node = curr_node->s_parent; 
	pathway_num++;     ///用于统计路径长度，便于下面换序
	initpoint++;
}
/*改变头尾顺序
i=0;
for(pAStarNode temp;i<pathway_num/2;i++)
{
	temp=path_stack[i];
	path_stack[i]=path_stack[pathway_num-i-1];
	path_stack[pathway_num-i-1]=temp;
}*/
//再初始化
for( i = 0; i < x_lenth; ++i )  
{  
    for ( j = 0; j < y_lenth; ++j )  
    {  
        map_maze[i][j].s_g = 0;  
        map_maze[i][j].s_h = 0;  
        map_maze[i][j].s_is_in_closetable = 0;  
        map_maze[i][j].s_is_in_opentable = 0;  
        map_maze[i][j].s_style = maze[i][j];  
        map_maze[i][j].s_x = i;  
        map_maze[i][j].s_y = j;  
        map_maze[i][j].s_parent = NULL;  

        if ( map_maze[i][j].s_style == pathway0 )  // 起点  
        {  
            start_node = &(map_maze[i][j]);  
        }  
        else if( map_maze[i][j].s_style ==  pathway1 )    // 终点   ENDNODE
        {  
            end_node = &(map_maze[i][j]);  
        }   
    }  

}
open_table[open_node_count++] = start_node;         // 起始点加入open表  

start_node->s_is_in_opentable = 1;               // 加入open表  
start_node->s_g = 0;  
start_node->s_h = abs(end_node->s_x - start_node->s_x) + abs(end_node->s_y - start_node->s_y);  
start_node->s_parent = curr_node;   
is_found = 0; 
workstate=endstate;
continue;
}
*/
#endif