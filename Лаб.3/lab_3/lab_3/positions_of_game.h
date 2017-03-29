#include<iostream>
class current_positions
{
public:char mtx[8][8];
	   current_positions()
	   {
		   memset(mtx, '0', sizeof(mtx));
	   }
private: struct comp_step
{
			int x0, y0, pos,beat;
};

public: comp_step c_step;

public: comp_step get_comp_step(int beat,int prx,int pry)
{
			comp_step res;
			res.beat = beat;
			int x, y;
			tree_of_game* head = build_tree(mtx, 0, 0, res.beat, prx, pry);
			make_depended_points(head);
			int et = 0;
			for (int i = 0; i < head->sons_n; i++)
			{
				if (head->sons[i]->difference>head->sons[et]->difference)
					et = i;
			}
			for (int i = 0; i < 8 ; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if ((mtx[i][j] == 'b' || mtx[i][j] == 'd') && (head->sons[et]->im_mtx[i][j] == '0'))
					{
						res.x0 = i; res.y0 = j;
					}
					else
					{
						if ((head->sons[et]->im_mtx[i][j] == 'b' || head->sons[et]->im_mtx[i][j] == 'd') && (mtx[i][j] == '0'))
						{
							x = i; y = j;
						}
					}
				}
			}
			int n = find_comp_possible_steps(mtx, res.x0, res.y0, res.beat);
			for (int i = 0; i < n;i++)
			if ((comp_posible_steps[0][i] == x) && (comp_posible_steps[1][i] == y)) res.pos = i;
			return res;
}

private: struct tree_of_game
{
			 char im_mtx[8][8];
			 int sons_n;
			 tree_of_game *sons[30];
			 int difference;
			 int step;
};
public: void for_check()
{
			int beat = 0;
			tree_of_game* head = build_tree(mtx, 0, 0,beat,-1,-1);
			make_depended_points(head);
}

private: void make_depended_points(tree_of_game *current)
{
			 if (current->sons_n > 0)
			 {
				 for (int i = 0; i < current->sons_n; i++)
				 {
					 make_depended_points(current->sons[i]);
				 }
				 int et = 0;
				 if (current->step == 0)
				 {
					 for (int i = 1; i < current->sons_n; i++)
					 {
						 if (current->sons[i]->difference>current->sons[et]->difference) et = i;
					 }
				 }
				 else 
				 for (int i = 1; i < current->sons_n; i++)
				 {
					 if (current->sons[i]->difference < current->sons[et]->difference) et = i;
				 }
				 current->difference += current->sons[et]->difference;
			 }
}

private: tree_of_game* build_tree(char (*im_mtx)[8], int lev,int step,int &beat, int x,int y)
{
			 tree_of_game* pos = new tree_of_game;
			 for (int i = 0; i < 8; i++)
			 for (int j = 0; j < 8; j++)
				 pos->im_mtx[i][j] = im_mtx[i][j];
			 bool flag = true;
			 pos->difference = find_dif(pos->im_mtx);
			 pos->sons_n = 0; pos->step = step;
			 if (lev < 6)
			 {
				 if (beat == 1)
				 {
					 if (step == 0 || lev == 0)
					 {
						 int num = find_comp_possible_steps(im_mtx, x, y, beat);
						 if (beat==1)
						 for (int k = 0; k < num; k++)
						 { 
							 int x0 = x; int y0 = y;
							 im_mtx[x0][y0] = '0';
							 int tx = comp_posible_steps[0][k]; int ty = comp_posible_steps[1][k];
							 int tbx = comp_posible_steps[2][k]; int tby = comp_posible_steps[3][k];
							 im_mtx[tx][ty] = pos->im_mtx[x][y];
							 if (beat == 1) { im_mtx[tbx][tby] = '0';  x = tx; y = ty; }
							 else { x = -1; y = -1; }
							 pos->sons[pos->sons_n] = build_tree(im_mtx, lev + 1, step, beat, x, y); pos->sons_n++;
							 im_mtx[tx][ty] = '0';
							 im_mtx[x0][y0] = pos->im_mtx[x0][y0];
							 im_mtx[tbx][tby] = pos->im_mtx[tbx][tby];
							 find_comp_possible_steps(im_mtx, x0, x0, beat);
						 }
						 else pos = build_tree(im_mtx, lev, 1, beat, -1, -1);
					 }
					 else
					 {
						 int num = find_possible_steps(im_mtx, x, y, beat);
						 if (beat == 1)
						 for (int k = 0; k < num; k++)
						 {
							 int x0 = x; int y0 = y;
							 im_mtx[x0][y0] = '0';
							 int tx = posible_steps[0][k]; int ty = posible_steps[1][k];
							 int tbx = posible_steps[2][k]; int tby = posible_steps[3][k];
							 im_mtx[tx][ty] = pos->im_mtx[x][y];
							 if (beat == 1) { im_mtx[tbx][tby] = '0';  x = tx; y = ty; }
							 else { x = -1; y = -1; }
							 pos->sons[pos->sons_n] = build_tree(im_mtx, lev + 1, step, beat, x, y); pos->sons_n++;
							 im_mtx[tx][ty] = '0';
							 im_mtx[x0][y0] = pos->im_mtx[x0][y0];
							 im_mtx[tbx][tby] = pos->im_mtx[tbx][tby];
							 find_possible_steps(im_mtx, x0, x0, beat);
						 }
						 else pos = build_tree(im_mtx, lev, 0, beat, -1, -1);
					 }
				 }
				 else
				 {
					 if (lev == 0 || step == 0)
					 {
						 for (int i = 0; i < 8; i++)
						 {
							 for (int j = 0; j < 8; j++)
							 {
								 if (im_mtx[i][j] == 'b' || im_mtx[i][j] == 'd')
								 {
									 find_comp_possible_steps(im_mtx, i, j, beat);
									 if (beat == 1) flag = false;
								 }
							 }
						 }



						 for (int i = 0; i < 8; i++)
						 {
							 for (int j = 0; j < 8; j++)
							 {
								 if (im_mtx[i][j] == 'b' || im_mtx[i][j] == 'd')
								 {
									 int num = find_comp_possible_steps(im_mtx, i, j, beat); if (beat == 1) { step = 0; }
									 else step = 1;
									 if (flag || (!flag && (beat == 1)))
									 {
										 for (int k = 0; k < num; k++)
										 {
											 im_mtx[i][j] = '0';
											 int tx = comp_posible_steps[0][k]; int ty = comp_posible_steps[1][k];
											 int tbx = comp_posible_steps[2][k]; int tby = comp_posible_steps[3][k];
											 im_mtx[tx][ty] = pos->im_mtx[i][j];
											 if (beat == 1) { im_mtx[tbx][tby] = '0';  x = tx; y = ty; }
											 else { x = -1; y = -1; }
											 pos->sons[pos->sons_n] = build_tree(im_mtx, lev + 1, step, beat,x,y); pos->sons_n++;
											 im_mtx[tx][ty] = '0';
											 im_mtx[i][j] = pos->im_mtx[i][j];
											 im_mtx[tbx][tby] = pos->im_mtx[tbx][tby];
											 find_comp_possible_steps(im_mtx, i, j, beat);
										 }
									 }
								 }
							 }
						 }
					 }
					 else
					 {
						 for (int i = 0; i < 8; i++)
						 {
							 for (int j = 0; j < 8; j++)
							 {
								 if (im_mtx[i][j] == 'w' || im_mtx[i][j] == 'q')
								 {
									 find_possible_steps(im_mtx, i, j, beat);
									 if (beat == 1) flag = false;
								 }
							 }
						 }




						 for (int i = 0; i < 8; i++)
						 {
							 for (int j = 0; j < 8; j++)
							 {
								 if (im_mtx[i][j] == 'w' || im_mtx[i][j] == 'q')
								 {
									 int num = find_possible_steps(im_mtx, i, j, beat); if (beat == 1) { step = 1; flag = false; }
									 else step = 0;
									 if (flag || (!flag && (beat == 1)))
									 {
										 for (int k = 0; k < num; k++)
										 {
											 im_mtx[i][j] = '0';
											 int tx = posible_steps[0][k]; int ty = posible_steps[1][k];
											 int tbx = posible_steps[2][k]; int tby = posible_steps[3][k];
											 if (beat == 1) { im_mtx[tbx][tby] = '0'; x = tx; y = ty; }
											 else { x = -1; y = -1; }
											 im_mtx[tx][ty] = pos->im_mtx[i][j];
											 pos->sons[pos->sons_n] = build_tree(im_mtx, lev + 1, step, beat,x,y); pos->sons_n++;
											 im_mtx[tx][ty] = '0'; im_mtx[i][j] = pos->im_mtx[i][j];
											 im_mtx[tbx][tby] = pos->im_mtx[tbx][tby];
											 find_possible_steps(im_mtx, i, j, beat);
										 }
									 }
								 }
							 }
						 }
					 }
				 }
			 }
			 return pos;

}
public: int posible_steps[4][13];
public: int comp_posible_steps[4][13];
private: int find_dif(char (*mtx_im)[8])
{
			 int w = 0; int b = 0;
			 for (int i = 0; i < 8; i++)
			 {
				 for (int j = 0; j < 8; j++)
				 {
					 switch (mtx_im[i][j])
					 {
					 case 'w':w++; break;
					 case 'q': w += 4; break;
					 case 'b':b++; break;
					 case 'd':b += 4; break;
					 }
				 }
			 }
			 return (b - w);
}
public:int find_possible_steps(char (*mtxw)[8], int x, int y,int &beat)
{
		   int col = 0;
		   beat = 0;
		   memset(posible_steps, 0, sizeof(posible_steps));


		   //for simple shashka
			   if (mtxw[x][y] == 'w')
			   {
				   if (x + 2 < 8 && y - 2 >= 0 && (mtxw[x + 1][y - 1] == 'b' || mtxw[x + 1][y - 1] == 'd') && mtxw[x + 2][y - 2] == '0')
				   {
					   beat = 1;
					   posible_steps[0][col] = x + 2;
					   posible_steps[1][col] = y - 2;
					   posible_steps[2][col] = x + 1;
					   posible_steps[3][col] = y - 1;
					   col++;
				   }
				   if (x -2 >=0 && y - 2 >= 0 && (mtxw[x -1][y - 1] == 'b' || mtxw[x -1][y - 1] == 'd') && mtxw[x -2][y - 2] == '0')
				   {
					   beat = 1;
					   posible_steps[0][col] = x -2;
					   posible_steps[1][col] = y - 2;
					   posible_steps[2][col] = x - 1;
					   posible_steps[3][col] = y - 1;
					   col++;
				   }
				   if (x + 2 < 8 && y +2 <8 && (mtxw[x + 1][y +1] == 'b' || mtxw[x + 1][y +1] == 'd') && mtxw[x + 2][y +2] == '0')
				   {
					   beat = 1;
					   posible_steps[0][col] = x + 2;
					   posible_steps[1][col] = y + 2;
					   posible_steps[2][col] = x + 1;
					   posible_steps[3][col] = y + 1;
					   col++;
				   }
				   if (x - 2 >= 0 && y + 2< 8 && (mtxw[x - 1][y + 1] == 'b' || mtxw[x - 1][y + 1] == 'd') && mtxw[x - 2][y + 2] == '0')
				   {
					   beat = 1;
					   posible_steps[0][col] = x - 2;
					   posible_steps[1][col] = y + 2;
					   posible_steps[2][col] = x - 1;
					   posible_steps[3][col] = y + 1;
					   col++;
				   }
				   if (beat==0)
				   {
					   if (x - 1 >= 0 && y - 1 >= 0 && mtxw[x - 1][y - 1] == '0')
					   {
						   posible_steps[0][col] = x - 1;
						   posible_steps[1][col] = y - 1;
						   col++;
					   }
					   if (x + 1 < 8 && y - 1 >= 0 && mtxw[x + 1][y - 1] == '0')
					   {
						   posible_steps[0][col] = x + 1;
						   posible_steps[1][col] = y - 1;
						   col++;
					   }
				   }
		   }
			   else
			   {

				   //for queen
				   if (mtxw[x][y] == 'q')
				   {

					   //-> + down
					   int i = 1;
					   while (x + i < 8 && y + i < 8 && mtxw[x + i][y + i] == '0'){ i++; }
					   if (x + i < 8 && y + i < 8)
					   {
						   if ((mtxw[x + i][y + i] == 'b' || mtxw[x + i][y + i] == 'd') && x + i + 1 < 8 && y + i + 1 < 8 && mtxw[x + i + 1][y + i + 1] == '0')
						   {
							   beat = 1;
							   posible_steps[0][col] = x + i + 1;
							   posible_steps[1][col] = y + i + 1;
							   posible_steps[2][col] = x + i;
							   posible_steps[3][col] = y + i;
							   col++;
							   for (int j = 1; x + i + j + 1 < 8 && y + i + j + 1 < 8 && mtxw[x + i + j + 1][y + i + j + 1] == '0'; j++)
							   {
								   posible_steps[0][col] = x + i + j + 1;
								   posible_steps[1][col] = y + i + j + 1;
								   posible_steps[2][col] = x + i;
								   posible_steps[3][col] = y + i;
								   col++;
							   }
						   }
					   }

					   //<- +down
					   i = 1;
					   while (x - i >= 0 && y + i < 8 && mtxw[x - i][y + i] == '0'){ i++; }
					   if (x - i >= 0 && y + i < 8)
					   {
						   if ((mtxw[x - i][y + i] == 'b' || mtxw[x - i][y + i] == 'd') && x - i - 1 >= 0 && y + i + 1 < 8 && mtxw[x - i - 1][y + i + 1] == '0')
						   {
							   beat = 1;
							   posible_steps[0][col] = x - i - 1;
							   posible_steps[1][col] = y + i + 1;
							   posible_steps[2][col] = x - i;
							   posible_steps[3][col] = y + i;
							   col++;
							   for (int j = 1; x - i - j - 1 >= 0 && y + i + j + 1 < 8 && mtxw[x - i - j - 1][y + i + j + 1] == '0'; j++)
							   {
								   posible_steps[0][col] = x - i - j - 1;
								   posible_steps[1][col] = y + i + j + 1;
								   posible_steps[2][col] = x - i;
								   posible_steps[3][col] = y + i;
								   col++;
							   }
						   }
					   }

					   //<- + up
					   i = 1;
					   while (x - i >= 0 && y - i >= 0 && mtxw[x - i][y - i] == '0'){ i++; }
					   if (x - i >= 0 && y - i >= 0)
					   {
						   if ((mtxw[x - i][y - i] == 'b' || mtxw[x - i][y - i] == 'd') && x - i - 1 >= 0 && y - i - 1 >= 0 && mtxw[x - i - 1][y - i - 1] == '0')
						   {
							   beat = 1;
							   posible_steps[0][col] = x - i - 1;
							   posible_steps[1][col] = y - i - 1;
							   posible_steps[2][col] = x - i;
							   posible_steps[3][col] = y - i;
							   col++;
							   for (int j = 1; x - i - j - 1 >= 0 && y - i - j - 1 >= 0 && mtxw[x - i - j - 1][y - i - j - 1] == '0'; j++)
							   {
								   posible_steps[0][col] = x - i - j - 1;
								   posible_steps[1][col] = y - i - j - 1;
								   posible_steps[2][col] = x - i;
								   posible_steps[3][col] = y - i;
								   col++;
							   }
						   }
					   }

					   //-> + up
					   i = 1;
					   while (x + i < 8 && y - i >= 0 && mtxw[x + i][y - i] == '0'){ i++; }
					   if (x + i < 8 && y - i >= 0)
					   {
						   if ((mtxw[x + i][y - i] == 'b' || mtxw[x + i][y - i] == 'd') && x + i + 1 < 8 && y - i - 1 >= 0 && mtxw[x + i + 1][y - i - 1] == '0')
						   {
							   beat = 1;
							   posible_steps[0][col] = x + i + 1;
							   posible_steps[1][col] = y - i - 1;
							   posible_steps[2][col] = x + i;
							   posible_steps[3][col] = y - i;
							   col++;
							   for (int j = 1; x + i + j + 1 < 8 && y - i - j - 1 >= 0 && mtxw[x + i + j + 1][y - i - j - 1] == '0'; j++)
							   {
								   posible_steps[0][col] = x + i + j + 1;
								   posible_steps[1][col] = y - i - j - 1;
								   posible_steps[2][col] = x + i;
								   posible_steps[3][col] = y - i;
								   col++;
							   }
						   }
					   }


					   //-> + down
					   i = 1;
					   while (x + i < 8 && y + i < 8 && mtxw[x + i][y + i] == '0'){ i++; }
					   if (x + i < 8 && y + i < 8)
					   {
						   if ((mtxw[x + i][y + i] == 'b' || mtxw[x + i][y + i] == 'd') && x + i + 1 < 8 && y + i + 1 < 8 && mtxw[x + i + 1][y + i + 1] == '0')
						   {
						   }
						   else
						   {
							   if (beat == 0)
							   {
								   for (int j = 1; x + j < x + i && y + j < y + i; j++)
								   {
									   posible_steps[0][col] = x + j;
									   posible_steps[1][col] = y + j;
									   col++;
								   }
							   }
						   }
					   }
					   else
					   {
						   if (beat == 0)
						   {
							   for (int j = 1; x + j < x + i && y + j < y + i; j++)
							   {
								   posible_steps[0][col] = x + j;
								   posible_steps[1][col] = y + j;
								   col++;
							   }
						   }
					   }

					   //<- +down
					   i = 1;
					   while (x - i >= 0 && y + i < 8 && mtxw[x - i][y + i] == '0'){ i++; }
					   if (x - i >= 0 && y + i < 8)
					   {
						   if ((mtxw[x - i][y + i] == 'b' || mtxw[x - i][y + i] == 'd') && x - i - 1 >= 0 && y + i + 1 < 8 && mtxw[x - i - 1][y + i + 1] == '0')
						   {
						   }
						   else
						   {
							   if (beat == 0)
							   {
								   for (int j = 1; x - j > x - i && y + j < y + i; j++)
								   {
									   posible_steps[0][col] = x - j;
									   posible_steps[1][col] = y + j;
									   col++;
								   }
							   }
						   }
					   }
					   else
					   {
						   if (beat == 0)
						   {
							   for (int j = 1; x - j > x - i && y + j < y + i; j++)
							   {
								   posible_steps[0][col] = x - j;
								   posible_steps[1][col] = y + j;
								   col++;
							   }
						   }
					   }


					   //<- + up
					   i = 1;
					   while (x - i >= 0 && y - i >= 0 && mtxw[x - i][y - i] == '0'){ i++; }
					   if (x - i >= 0 && y - i >= 0)
					   {
						   if ((mtxw[x - i][y - i] == 'b' || mtxw[x - i][y - i] == 'd') && x - i - 1 >= 0 && y - i - 1 >= 0 && mtxw[x - i - 1][y - i - 1] == '0')
						   {
						   }
						   else
						   {
							   if (beat == 0)
							   {
								   for (int j = 1; x - j > x - i && y - j > y - i; j++)
								   {
									   posible_steps[0][col] = x - j;
									   posible_steps[1][col] = y - j;
									   col++;
								   }
							   }
						   }
					   }
					   else
					   {
						   if (beat == 0)
						   {
							   for (int j = 1; x - j > x - i && y - j > y - i; j++)
							   {
								   posible_steps[0][col] = x - j;
								   posible_steps[1][col] = y - j;
								   col++;
							   }
						   }
					   }


					   //-> + up
					   i = 1;
					   while (x + i < 8 && y - i >= 0 && mtxw[x + i][y - i] == '0'){ i++; }
					   if (x + i < 8 && y - i >= 0)
					   {
						   if ((mtxw[x + i][y - i] == 'b' || mtxw[x + i][y - i] == 'd') && x + i + 1 < 8 && y - i - 1 >= 0 && mtxw[x + i + 1][y - i - 1] == '0')
						   {
						   }
						   else
						   {
							   if (beat == 0)
							   {
								   for (int j = 1; x + j < x + i && y - j > y - i; j++)
								   {
									   posible_steps[0][col] = x + j;
									   posible_steps[1][col] = y - j;
									   col++;
								   }
							   }
						   }
					   }
					   else
					   {
						   if (beat == 0)
						   {
							   for (int j = 1; x + j < x + i && y - j > y - i; j++)
							   {
								   posible_steps[0][col] = x + j;
								   posible_steps[1][col] = y - j;
								   col++;
							   }
						   }
					   }
				   }
				   }
		return col;
}


public:int find_comp_possible_steps(char (*mtxc)[8],int x, int y, int &beat)
{
		   int col = 0;
		   beat = 0;
		   memset(comp_posible_steps, 0, sizeof(comp_posible_steps));


		   //for simple shashka
		   if (mtxc[x][y] == 'b')
		   {
			   if (x + 2 < 8 && y - 2 >= 0 && (mtxc[x + 1][y - 1] == 'w' || mtxc[x + 1][y - 1] == 'q') && mtxc[x + 2][y - 2] == '0')
			   {
				   beat = 1;
				   comp_posible_steps[0][col] = x + 2;
				   comp_posible_steps[1][col] = y - 2;
				   comp_posible_steps[2][col] = x + 1;
				   comp_posible_steps[3][col] = y - 1;
				   col++;
			   }
			   if (x - 2 >= 0 && y - 2 >= 0 && (mtxc[x - 1][y - 1] == 'w' || mtxc[x - 1][y - 1] == 'q') && mtxc[x - 2][y - 2] == '0')
			   {
				   beat = 1;
				   comp_posible_steps[0][col] = x - 2;
				   comp_posible_steps[1][col] = y - 2;
				   comp_posible_steps[2][col] = x - 1;
				   comp_posible_steps[3][col] = y - 1;
				   col++;
			   }
			   if (x + 2 < 8 && y + 2 <8 && (mtxc[x + 1][y + 1] == 'w' || mtxc[x + 1][y + 1] == 'q') && mtxc[x + 2][y + 2] == '0')
			   {
				   beat = 1;
				   comp_posible_steps[0][col] = x + 2;
				   comp_posible_steps[1][col] = y + 2;
				   comp_posible_steps[2][col] = x + 1;
				   comp_posible_steps[3][col] = y + 1;
				   col++;
			   }
			   if (x - 2 >= 0 && y + 2< 8 && (mtxc[x - 1][y + 1] == 'w' || mtxc[x - 1][y + 1] == 'q') && mtxc[x - 2][y + 2] == '0')
			   {
				   beat = 1;
				   comp_posible_steps[0][col] = x - 2;
				   comp_posible_steps[1][col] = y + 2;
				   comp_posible_steps[2][col] = x - 1;
				   comp_posible_steps[3][col] = y + 1;
				   col++;
			   }
			   if (beat == 0)
			   {
				   if (x - 1 >= 0 && y + 1 <8  && mtxc[x - 1][y + 1] == '0')
				   {
					   comp_posible_steps[0][col] = x - 1;
					   comp_posible_steps[1][col] = y + 1;
					   col++;
				   }
				   if (x + 1 < 8 && y + 1 < 8 && mtxc[x + 1][y + 1] == '0')
				   {
					   comp_posible_steps[0][col] = x + 1;
					   comp_posible_steps[1][col] = y + 1;
					   col++;
				   }
			   }
		   }
		   else
		   {

			   //for queen
			   if (mtxc[x][y] == 'd')
			   {

				   //-> + down
				   int i = 1;
				   while (x + i < 8 && y + i < 8 && mtxc[x + i][y + i] == '0'){ i++; }
				   if (x + i < 8 && y + i < 8)
				   {
					   if ((mtxc[x + i][y + i] == 'w' || mtxc[x + i][y + i] == 'q') && x + i + 1 < 8 && y + i + 1 < 8 && mtxc[x + i + 1][y + i + 1] == '0')
					   {
						   beat = 1;
						   comp_posible_steps[0][col] = x + i + 1;
						   comp_posible_steps[1][col] = y + i + 1;
						   comp_posible_steps[2][col] = x + i;
						   comp_posible_steps[3][col] = y + i;
						   col++;
						   for (int j = 1; x + i + j + 1 < 8 && y + i + j + 1 < 8 && mtxc[x + i + j + 1][y + i + j + 1] == '0'; j++)
						   {
							   comp_posible_steps[0][col] = x + i + j + 1;
							   comp_posible_steps[1][col] = y + i + j + 1;
							   comp_posible_steps[2][col] = x + i;
							   comp_posible_steps[3][col] = y + i;
							   col++;
						   }
					   }
				   }

				   //<- +down
				   i = 1;
				   while (x - i >= 0 && y + i < 8 && mtxc[x - i][y + i] == '0'){ i++; }
				   if (x - i >= 0 && y + i < 8)
				   {
					   if ((mtxc[x - i][y + i] == 'w' || mtxc[x - i][y + i] == 'q') && x - i - 1 >= 0 && y + i + 1 < 8 && mtxc[x - i - 1][y + i + 1] == '0')
					   {
						   beat = 1;
						   comp_posible_steps[0][col] = x - i - 1;
						   comp_posible_steps[1][col] = y + i + 1;
						   comp_posible_steps[2][col] = x - i;
						   comp_posible_steps[3][col] = y + i;
						   col++;
						   for (int j = 1; x - i - j - 1 >= 0 && y + i + j + 1 < 8 && mtxc[x - i - j - 1][y + i + j + 1] == '0'; j++)
						   {
							   comp_posible_steps[0][col] = x - i - j - 1;
							   comp_posible_steps[1][col] = y + i + j + 1;
							   comp_posible_steps[2][col] = x - i;
							   comp_posible_steps[3][col] = y + i;
							   col++;
						   }
					   }
				   }

				   //<- + up
				   i = 1;
				   while (x - i >= 0 && y - i >= 0 && mtxc[x - i][y - i] == '0'){ i++; }
				   if (x - i >= 0 && y - i >= 0)
				   {
					   if ((mtxc[x - i][y - i] == 'w' || mtxc[x - i][y - i] == 'q') && x - i - 1 >= 0 && y - i - 1 >= 0 && mtxc[x - i - 1][y - i - 1] == '0')
					   {
						   beat = 1;
						   comp_posible_steps[0][col] = x - i - 1;
						   comp_posible_steps[1][col] = y - i - 1;
						   comp_posible_steps[2][col] = x - i;
						   comp_posible_steps[3][col] = y - i;
						   col++;
						   for (int j = 1; x - i - j - 1 >= 0 && y - i - j - 1 >= 0 && mtxc[x - i - j - 1][y - i - j - 1] == '0'; j++)
						   {
							   comp_posible_steps[0][col] = x - i - j - 1;
							   comp_posible_steps[1][col] = y - i - j - 1;
							   comp_posible_steps[2][col] = x - i;
							   comp_posible_steps[3][col] = y - i;
							   col++;
						   }
					   }
				   }

				   //-> + up
				   i = 1;
				   while (x + i < 8 && y - i >= 0 && mtxc[x + i][y - i] == '0'){ i++; }
				   if (x + i < 8 && y - i >= 0)
				   {
					   if ((mtxc[x + i][y - i] == 'w' || mtxc[x + i][y - i] == 'q') && x + i + 1 < 8 && y - i - 1 >= 0 && mtxc[x + i + 1][y - i - 1] == '0')
					   {
						   beat = 1;
						   comp_posible_steps[0][col] = x + i + 1;
						   comp_posible_steps[1][col] = y - i - 1;
						   comp_posible_steps[2][col] = x + i;
						   comp_posible_steps[3][col] = y - i;
						   col++;
						   for (int j = 1; x + i + j + 1 < 8 && y - i - j - 1 >= 0 && mtxc[x + i + j + 1][y - i - j - 1] == '0'; j++)
						   {
							   comp_posible_steps[0][col] = x + i + j + 1;
							   comp_posible_steps[1][col] = y - i - j - 1;
							   comp_posible_steps[2][col] = x + i;
							   comp_posible_steps[3][col] = y - i;
							   col++;
						   }
					   }
				   }


				   //-> + down
				   i = 1;
				   while (x + i < 8 && y + i < 8 && mtxc[x + i][y + i] == '0'){ i++; }
				   if (x + i < 8 && y + i < 8)
				   {
					   if ((mtxc[x + i][y + i] == 'w' || mtxc[x + i][y + i] == 'q') && x + i + 1 < 8 && y + i + 1 < 8 && mtxc[x + i + 1][y + i + 1] == '0')
					   {
					   }
					   else
					   {
						   if (beat == 0)
						   {
							   for (int j = 1; x + j < x + i && y + j < y + i; j++)
							   {
								   comp_posible_steps[0][col] = x + j;
								   comp_posible_steps[1][col] = y + j;
								   col++;
							   }
						   }
					   }
				   }
				   else
				   {
					   if (beat == 0)
					   {
						   for (int j = 1; x + j < x + i && y + j < y + i; j++)
						   {
							   comp_posible_steps[0][col] = x + j;
							   comp_posible_steps[1][col] = y + j;
							   col++;
						   }
					   }
				   }

				   //<- +down
				   i = 1;
				   while (x - i >= 0 && y + i < 8 && mtxc[x - i][y + i] == '0'){ i++; }
				   if (x - i >= 0 && y + i < 8)
				   {
					   if ((mtxc[x - i][y + i] == 'w' || mtxc[x - i][y + i] == 'q') && x - i - 1 >= 0 && y + i + 1 < 8 && mtxc[x - i - 1][y + i + 1] == '0')
					   {
					   }
					   else
					   {
						   if (beat == 0)
						   {
							   for (int j = 1; x - j > x - i && y + j < y + i; j++)
							   {
								   comp_posible_steps[0][col] = x - j;
								   comp_posible_steps[1][col] = y + j;
								   col++;
							   }
						   }
					   }
				   }
				   else
				   {
					   if (beat == 0)
					   {
						   for (int j = 1; x - j > x - i && y + j < y + i; j++)
						   {
							   comp_posible_steps[0][col] = x - j;
							   comp_posible_steps[1][col] = y + j;
							   col++;
						   }
					   }
				   }


				   //<- + up
				   i = 1;
				   while (x - i >= 0 && y - i >= 0 && mtxc[x - i][y - i] == '0'){ i++; }
				   if (x - i >= 0 && y - i >= 0)
				   {
					   if ((mtxc[x - i][y - i] == 'w' || mtxc[x - i][y - i] == 'q') && x - i - 1 >= 0 && y - i - 1 >= 0 && mtxc[x - i - 1][y - i - 1] == '0')
					   {
					   }
					   else
					   {
						   if (beat == 0)
						   {
							   for (int j = 1; x - j > x - i && y - j > y - i; j++)
							   {
								   comp_posible_steps[0][col] = x - j;
								   comp_posible_steps[1][col] = y - j;
								   col++;
							   }
						   }
					   }
				   }
				   else
				   {
					   if (beat == 0)
					   {
						   for (int j = 1; x - j > x - i && y - j > y - i; j++)
						   {
							   comp_posible_steps[0][col] = x - j;
							   comp_posible_steps[1][col] = y - j;
							   col++;
						   }
					   }
				   }


				   //-> + up
				   i = 1;
				   while (x + i < 8 && y - i >= 0 && mtxc[x + i][y - i] == '0'){ i++; }
				   if (x + i < 8 && y - i >= 0)
				   {
					   if ((mtxc[x + i][y - i] == 'w' || mtxc[x + i][y - i] == 'q') && x + i + 1 < 8 && y - i - 1 >= 0 && mtxc[x + i + 1][y - i - 1] == '0')
					   {
					   }
					   else
					   {
						   if (beat == 0)
						   {
							   for (int j = 1; x + j < x + i && y - j > y - i; j++)
							   {
								   comp_posible_steps[0][col] = x + j;
								   comp_posible_steps[1][col] = y - j;
								   col++;
							   }
						   }
					   }
				   }
				   else
				   {
					   if (beat == 0)
					   {
						   for (int j = 1; x + j < x + i && y - j > y - i; j++)
						   {
							   comp_posible_steps[0][col] = x + j;
							   comp_posible_steps[1][col] = y - j;
							   col++;
						   }
					   }
				   }
			   }
		   }
		   return col;
}
};
