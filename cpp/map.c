#include "map.h"  
/*
int maze[x_lenth][y_lenth] ={           // 仅仅为了好赋值给map_maze  
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
						{ 3,0,0,0,0,3,3,3,0,3 }, ////新加
                    };*/
#if 0   ///7.19
int maze[x_lenth][y_lenth] ={
						/*-----------0------*/																																											 /*-----------10------*/
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0}, //1 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0}, //2 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0}, //3 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0}, //4 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,9,0,0 ,0,0,0,0,0,0,0}, //5 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,9,9,0 ,0,0,0,0,0,0,0}, //6 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,9,9 ,0,0,0,0,0,0,0}, //7 
						/*-----------2------*/
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,9 ,9,0,0,0,0,0,0}, //8 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 9,9,9,9,9,9,9,9,0,0 ,0,0,0,0,0,0,0,0,0,0 ,9,0,0,0,0,0,0}, //9 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 9,9,9,9,9,9,9,9,0,0 ,0,0,0,0,0,0,0,0,0,0 ,9,0,0,0,0,0,0}, //10 
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,9, 9,9,9,9,9,9,9,9,9,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0}, //1 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,9, 9,9,9,9,9,9,9,9,9,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0}, //2 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,9,9, 9,9,9,9,9,9,9,9,9,9 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0}, //3 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,9,9,9,0,0,9,9, 9,9,9,9,9,9,9,9,9,9 ,0,0,9,9,0,0,0,0,0,0 ,0,0,0,0,0,0,0}, //4 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,9,9,9,0,9,9,9, 9,9,9,9,9,9,9,9,9,9 ,9,0,9,9,0,0,0,0,0,0 ,0,0,0,0,0,0,0}, //5 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,9,9,9, 9,9,9,9,9,9,9,9,9,9 ,9,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0}, //6 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,9,9, 9,9,9,9,9,9,9,9,9,9 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0}, //7 
						/*-----------1------*/
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,9,9, 9,9,9,9,9,9,9,9,9,9 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0}, //8 
                        { 0,0,0,0,0,0,0,9,0,0 ,0,0,0,0,0,0,0,0,0,9, 9,9,9,9,9,9,9,9,9,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0}, //9 
                        { 0,0,0,0,0,0,0,9,9,0 ,0,0,0,0,0,0,0,0,0,9, 9,9,9,9,9,9,9,9,9,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0}, //10 
						{ 0,0,0,0,0,0,0,0,9,0 ,0,0,0,0,0,0,0,0,0,0, 9,9,9,9,9,9,9,9,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0}, //1 
                        { 0,0,0,0,0,0,0,0,0,9 ,0,0,0,0,0,0,0,0,0,0, 9,9,9,9,9,9,9,9,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0}, //2 
                        { 0,0,0,0,0,0,0,0,0,9 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0}, //3 
                        { 0,0,0,0,0,0,0,0,0,0 ,9,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0}, //4 
                        { 0,0,0,0,0,0,0,0,0,0 ,9,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0}, //5 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0}, //6 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0}, //7 
                       

};
#endif
#if 1
int maze[x_lenth][y_lenth] ={
						/*-----------0------*/																																											 /*-----------10------*/
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //1 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //2 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //3 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //4 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //5 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //6 
                        { 0,0,0,0,0,0,0,0,9,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //7 
						{ 0,0,0,0,0,0,9,9,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //8 
                        { 0,0,0,0,9,9,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //9 
                        { 0,0,0,9,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //10 
						/*-----------1------*/
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //1 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //2 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //3 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,9,9,0,0,0,0,0,0, 0,0,0,0}, //4 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,9,9,0,0,0,0,0,0, 0,0,0,0}, //5 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,9,9,0,0,0,0,0,0, 0,0,0,0}, //6 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //7 
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //8 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //9 
                        { 0,0,0,0,0,0,0,0,0,0 ,9,9,9,9,0,0,0,0,0,0, 0,0,0,0}, //10 
						/*-----------2------*/
						{ 0,0,0,0,0,0,0,0,9,9 ,9,9,9,9,9,9,0,0,0,0, 0,0,0,0}, //1 
                        { 0,0,0,0,0,0,0,0,9,9 ,9,9,9,9,9,9,0,0,0,0, 0,0,0,0}, //2 
                        { 0,0,0,0,0,0,0,0,9,9 ,9,9,9,9,9,9,0,0,0,0, 0,0,0,0}, //3 
                        { 0,0,0,0,0,0,0,0,9,9 ,9,9,9,9,9,9,0,0,0,0, 0,0,0,0}, //4 
                        { 0,0,0,0,0,0,0,0,9,9 ,9,9,9,9,9,9,0,0,0,0, 0,0,0,0}, //5 
                        { 0,0,0,0,0,0,0,0,9,9 ,9,9,9,9,9,9,0,0,0,0, 0,0,0,0}, //6 
                        { 0,0,0,0,0,0,0,0,0,0 ,9,9,9,9,0,0,0,0,0,0, 0,0,0,0}, //7 
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //8 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //9 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //10 
						/*-----------3------*/
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //1 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //2 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,9,9,0,0,0,0,0,0, 0,0,0,0}, //3 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,9,9,0,0,0,0,0,0, 0,0,0,0}, //4 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 9,0,0,0}, //5 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,9, 0,0,0,0}, //6 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,9,0, 0,0,0,0}, //7 
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,9,0,0, 0,0,0,0}, //8 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,9,9,0,0,0, 0,0,0,0}, //9 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //10 
						/*-----------4------*/
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //1 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //2 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //3 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //4 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //5 
                        // { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //6 
                        // { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //7 
						// { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //8 
                        // { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //9 
						// { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0}, //10                       
						
};
#endif

#if 0
int maze[x_lenth][y_lenth] ={
						/*-----------1------*/
						{ 1,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,3 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //1 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //2 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //3 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //4 
                        { 0,0,9,9,9,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //5 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //6 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //7 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //8 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //9 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //10 
                        /*-----------2------*/
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //1 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //2 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //3 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //4 
                        { 0,9,9,9,9,9,9,9,9,9 ,9,9,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //5 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //6 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //7 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //8 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //9 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //10 
						/*-----------3------*/
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //1 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //2 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //3 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //4 
                        { 0,0,9,9,9,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //5 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //6 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //7 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //8 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //9 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //10 
						/*-----------4------*/
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //1 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //2 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //3 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //4 
                        { 0,0,9,9,9,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //5 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //6 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //7 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //8 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //9 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //10 
						/*-----------5------*/
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //1 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //2 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //3 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //4 
                        { 0,0,9,9,9,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //5 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //6 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //7 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //8 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //9 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,8 /*8*/,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //10 
						 /*-----------6------*/
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //1 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //2 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //3 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //4 
                        { 0,0,9,9,9,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //5 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //6 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //7 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //8 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //9 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //10 
						/*-----------7------*/
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //1 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //2 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //3 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //4 
                        { 0,0,9,9,9,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //5 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //6 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //7 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //8 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //9 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //10 
						 /*-----------8------*/
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //1 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //2 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //3 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //4 
                        { 0,0,9,9,9,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //5 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //6 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //7 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //8 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //9 
                        { 2,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0 }, //10 

};

int maze[x_lenth][y_lenth] ={
						/*-----------1------*/
						{ 1,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,3 }, //1 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //2 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //3 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //4 
                        { 0,0,9,9,9,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //5 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //6 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //7 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //8 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //9 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //10 
                        /*-----------2------*/
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //1 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //2 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //3 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //4 
                        { 0,0,9,9,9,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //5 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //6 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //7 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //8 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //9 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //10 
						/*-----------3------*/
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //1 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //2 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //3 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //4 
                        { 0,0,9,9,9,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //5 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //6 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //7 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //8 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //9 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //10 
						/*-----------4------*/
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //1 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //2 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //3 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //4 
                        { 0,0,9,9,9,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //5 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //6 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //7 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //8 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //9 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //10 
						/*-----------5------*/
						{ 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //1 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //2 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //3 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,9,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //4 
                        { 0,0,9,9,9,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //5 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //6 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //7 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //8 
                        { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, //9 
                        { 2,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,8 }, //10 

};
#endif


