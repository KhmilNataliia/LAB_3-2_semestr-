#include<iostream>
#include<string>
#pragma once
#include "positions_of_game.h"


namespace lab_3 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Сводка для game
	/// </summary>
	public ref class game : public System::Windows::Forms::Form
	{
	public:
		game(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			current_positions cur_game;

			//
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~game()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;


	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  startNewGameToolStripMenuItem;


	protected:

	protected:

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->startNewGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(757, 155);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(174, 42);
			this->label1->TabIndex = 0;
			this->label1->Text = L"your score:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(763, 281);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(168, 39);
			this->label2->TabIndex = 1;
			this->label2->Text = L"opponent\'s:";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::PaleGreen;
			this->textBox1->Enabled = false;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(764, 213);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(46, 45);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"0";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::Salmon;
			this->textBox2->Enabled = false;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(764, 336);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(46, 45);
			this->textBox2->TabIndex = 5;
			this->textBox2->Text = L"0";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->startNewGameToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(930, 36);
			this->menuStrip1->TabIndex = 6;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// startNewGameToolStripMenuItem
			// 
			this->startNewGameToolStripMenuItem->BackColor = System::Drawing::Color::MediumSpringGreen;
			this->startNewGameToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->startNewGameToolStripMenuItem->Name = L"startNewGameToolStripMenuItem";
			this->startNewGameToolStripMenuItem->Size = System::Drawing::Size(164, 32);
			this->startNewGameToolStripMenuItem->Text = L"start new game";
			this->startNewGameToolStripMenuItem->Click += gcnew System::EventHandler(this, &game::startNewGameToolStripMenuItem_Click);
			// 
			// game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(930, 864);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"game";
			this->Text = L"game";
			this->Load += gcnew System::EventHandler(this, &game::game_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &game::game_Paint);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &game::game_MouseClick);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int pos_board_x = 37;
		int pos_board_y = 94;
		int board_w = 720;
		int board_h = 720;
		bool client_turn = true;
		bool cells_lighted = false;
		bool shashka_choosen = false;
		int beat_client=0;
		int beat_comp=0;
		int cur_num = 0;
		int choosen_x;
		int choosen_y;
		int col_white;
		int col_black;
		bool end_of_game=false;
		Graphics^ board;
		current_positions *cur_game = new current_positions();
	private: System::Void game_Load(System::Object^  sender, System::EventArgs^  e) 
	{
				 game::BackColor = Color::OliveDrab;
				 board = this->CreateGraphics();
				 
	}
	private: Void light_cells( bool on)
	{
				 for (int i = 0; i < cur_num; i++)
				 {
					 if (on)
					 {
						 board->DrawRectangle(System::Drawing::Pens::Black, cur_game->posible_steps[0][i] * board_w / 8 + pos_board_x, cur_game->posible_steps[1][i] * board_h / 8 + pos_board_y, board_w / 8, board_h / 8);
					 }
					 else
					 {
						 board->DrawRectangle(System::Drawing::Pens::Tan, cur_game->posible_steps[0][i] * board_w / 8 + pos_board_x, cur_game->posible_steps[1][i] * board_h / 8 + pos_board_y, board_w / 8, board_h / 8);
					 }
				 }
	}

	private: Void move_white_shashka(int x0, int y0, int p,int dam,int beat)
	{ 
				 System::Drawing::Brush^ cells_black = gcnew SolidBrush(Color::Tan);
				 int x = cur_game->posible_steps[0][p];
				 int y = cur_game->posible_steps[1][p];
				 board->FillRectangle(cells_black, board_w / 8 * x0+pos_board_x, board_h / 8 * y0+pos_board_y, board_w / 8, board_h / 8);
                 draw_white_shashka(x,y, dam);
				 board->DrawRectangle(System::Drawing::Pens::Black, pos_board_x, pos_board_y, board_w - 1, board_h - 1);
				 if (beat>0)
				 {
					 int xb=cur_game->posible_steps[2][p];
					 int yb = cur_game->posible_steps[3][p];
					 cur_game->mtx[xb][yb] = '0';
					 board->FillRectangle(cells_black, board_w / 8 * xb + pos_board_x, board_h / 8 * yb + pos_board_y, board_w / 8, board_h / 8);
				 }
	}
	private: Void move_black_shashka(int x0, int y0, int p, int dam,int beat)
	{
				 System::Drawing::Brush^ cells_black = gcnew SolidBrush(Color::Tan);
				 int x = cur_game->comp_posible_steps[0][p];
				 int y = cur_game->comp_posible_steps[1][p];
				 _sleep(100);
				 board->FillRectangle(cells_black, board_w / 8 * x0+pos_board_x, board_h / 8 * y0+pos_board_y, board_w / 8, board_h / 8);
				 _sleep(100);
				 draw_black_shashka(x, y, dam);
				 board->DrawRectangle(System::Drawing::Pens::Black, pos_board_x, pos_board_y, board_w - 1, board_h - 1);
				 if (beat > 0)
				 {
					 int xb = cur_game->comp_posible_steps[2][p];
					 int yb = cur_game->comp_posible_steps[3][p];
					 cur_game->mtx[xb][yb] = '0';
					 board->FillRectangle(cells_black, board_w / 8 * xb + pos_board_x, board_h / 8 * yb + pos_board_y, board_w / 8, board_h / 8);
				 }
	}

	private: Void draw_white_shashka(int x, int y,int dam)
	{
				 System::Drawing::Brush^ shashka_white = gcnew SolidBrush(Color::Cornsilk);
				 System::Drawing::Brush^ blackPen = gcnew SolidBrush(Color::Black);
				 int w = board_w/8; int h = board_h/8;
				 if (dam == 0)
					 board->FillEllipse(shashka_white, w * x + 5+pos_board_x, h* y + 5+pos_board_y, w - 10, h - 10);
				 else
				 {
					 board->FillEllipse(shashka_white, w * x + 5+pos_board_x, h* y + 5+pos_board_y, w - 10, h - 10);
					 array<PointF>^ points = {
						 PointF(w * x + 10 + (w - 20) / 6 + pos_board_x, h* y + 10 + 3 * (h - 20) / 4 + pos_board_y),
						 PointF(w * x + 10 + (w - 20) / 6 + pos_board_x, h* y + pos_board_y + 10 + (h - 20) / 4),
						 PointF(w * x + 10 + (w - 20) / 3 + pos_board_x, h* y + 10 + (h - 20) / 2 + pos_board_y),
						 PointF(w * x + 10 + (w - 20) / 2 + pos_board_x, h* y + 10 + (h - 20) / 4 + pos_board_y),
						 PointF(w * x + 10 + 2 * (w - 20) / 3 + pos_board_x, h* y + 10 + (h - 20) / 2 + pos_board_y),
						 PointF(w * x + 10 + 5 * (w - 20) / 6 + pos_board_x, h* y + 10 + (h - 20) / 4 + pos_board_y),
						 PointF(w * x + 10 + 5 * (w - 20) / 6 + pos_board_x, h* y + 10 + 3 * (h - 20) / 4 + pos_board_y)
					 };
					 board->FillClosedCurve(blackPen, points);
				 }
	}
			
	private: Void draw_black_shashka(int x, int y,int dam)
	{
				 System::Drawing::Brush^ shashka_red = gcnew SolidBrush(Color::Maroon);
				 int w = board_w/8; int h = board_h/8;
				 if (dam==0)
				 board->FillEllipse(shashka_red, w* x + 5+pos_board_x,h* y + 5+pos_board_y,w - 10, h - 10);
				 else
				 {
					 board->FillEllipse(shashka_red, w* x + 5+pos_board_x, h* y + 5+pos_board_y, w - 10, h - 10);
					 Brush^ blackPen = gcnew SolidBrush(Color::Black);
					 array<PointF>^ points = {
						 PointF(w * x + 10 + (w - 20) / 6+pos_board_x, h* y + 10 + 3 * (h - 20) / 4+pos_board_y),
						 PointF(w * x + 10 + (w - 20) / 6+pos_board_x, h* y+pos_board_y + 10+ (h - 20) / 4),
						 PointF(w * x + 10 + (w - 20) / 3+pos_board_x, h* y + 10 + (h - 20) / 2+pos_board_y),
						 PointF(w * x + 10 + (w - 20) / 2+pos_board_x, h* y + 10 + (h - 20) / 4+pos_board_y),
						 PointF(w * x + 10 + 2 * (w - 20) / 3+pos_board_x, h* y + 10 + (h - 20) / 2+pos_board_y),
						 PointF(w * x + 10 + 5 * (w - 20) / 6+pos_board_x, h* y + 10 + (h - 20) / 4+pos_board_y),
						 PointF(w * x + 10 + 5 * (w - 20) / 6+pos_board_x, h* y + 10 + 3 * (h - 20) / 4+pos_board_y)
					 };
					 board->FillClosedCurve(blackPen, points);
				 }
	}
	private: System::Void game_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 System::Drawing::Brush^ cells_black = gcnew SolidBrush(Color::Tan);
				 System::Drawing::Brush^ cells_white = gcnew SolidBrush(Color::AntiqueWhite);
				 System::Drawing::Brush^ shashka_red = gcnew SolidBrush(Color::Maroon);
				 for (int i = 0; i < 8; i++)
				 {
					 if (i % 2 == 0)
					 {
						 for (int j = 0; j < 8; j++)
						 {
							 if (j % 2 == 0)
							 {
								 board->FillRectangle(cells_white, board_w / 8 * j+pos_board_x, board_h / 8 * i+pos_board_y, board_w / 8, board_h / 8);

							 }
							 else
							 {
								 board->FillRectangle(cells_black, board_w / 8 * j+pos_board_x, board_h / 8 * i+pos_board_y, board_w / 8, board_h / 8);
								 if (i < 3)
								 {
									 draw_black_shashka(j, i, 0);
									 cur_game->mtx[j][i] = 'b';
								 }
								 if (i >4)
								 {
									 draw_white_shashka(j, i, 0);
									cur_game->mtx[j][i] = 'w';
								 }
							 }

						 }
					 }
					 else
					 {
						 for (int j = 0; j < 8; j++)
						 {
							 if (j % 2 == 0)
							 {
								 board->FillRectangle(cells_black, board_w / 8 * j+pos_board_x, board_h / 8 * i+pos_board_y, board_w / 8, board_h / 8);
								 if (i < 3)
								 {
									 draw_black_shashka(j, i, 0);
									 cur_game->mtx[j][i] = 'b';
								 }
								 if (i >4)
								 {
									 draw_white_shashka(j, i, 0);
									 cur_game->mtx[j][i] = 'w';
								 }
							 }
							 else
							 {
								 board->FillRectangle(cells_white, board_w / 8 * j+pos_board_x, board_h / 8 * i+pos_board_y, board_w / 8, board_h / 8);
							 }

						 }
					 }
				 }
				 board->DrawRectangle(System::Drawing::Pens::Black, pos_board_x, pos_board_y, board_w - 1, board_h - 1);
	}
private: System::Void game_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
{ 
			 if (!end_of_game)
			 {
				 int X = e->Location.X;
				 int Y = e->Location.Y;
				 X = X - pos_board_x;
				 Y = Y - pos_board_y;
				 if (X > 0 && Y > 0 && X < board_w && Y < board_h)
				 {
					 int i = X / (board_w / 8);
					 int j = Y / (board_h / 8);
					 doing_step(i, j);
					 calc_n_white();
					 calc_n_black();
					 textBox1->Text = (12-col_black).ToString();
					 textBox2->Text = (12-col_white).ToString();
				 }
			 }
			 if (!end_of_game)
			 {
				 do_comp_step(0, -1, -1);
				 calc_n_black();
				 calc_n_white();
				 textBox1->Text = (12 - col_black).ToString();
				 textBox2->Text = (12 - col_white).ToString();
			 }
}

		 private: void calc_n_white()
		 {
					  int col = 0;
					  int col_st = 0; int b = 0;
					  for (int i = 0; i < 8; i++)
					  {
						  for (int j = 0; j < 8; j++)
						  {
							  if ((cur_game->mtx[i][j] == 'w') || (cur_game->mtx[i][j] == 'q')) {
								  col++;
								  col_st += cur_game->find_possible_steps(cur_game->mtx, i, j, b);
							  }

						  }
					  }
					  if (col == 0 || col_st==0)
					  { 
						  end_of_game = true; 
						  MessageBox::Show("You loose the game!!!");
					  }
					  col_white = col;
		 }

		 private: void calc_n_black()
		 {
					  int col = 0;
					  int col_st =1; int b = 0;
					  for (int i = 0; i < 8; i++)
					  {
						  for (int j = 0; j < 8; j++)
						  {
							  if ((cur_game->mtx[i][j] == 'b') || (cur_game->mtx[i][j] == 'd')){
								  col++;
								  col_st += cur_game->find_comp_possible_steps(cur_game->mtx, i, j, b);
							  }
						  }
					  }
					  if (col == 0 || col_st==0)
					  {
						  end_of_game = true;
						  MessageBox::Show("You win the game!!!");
					  }
					  col_black = col;
		 }

		 private: Void do_comp_step(int beat, int prx,int pry)
		 {
					  if (!client_turn)
					  {
							  cur_game->c_step = cur_game->get_comp_step(beat, prx, pry);
							  beat = cur_game->c_step.beat;
							  int dam;
							  if (cur_game->mtx[cur_game->c_step.x0][cur_game->c_step.y0] == 'd') dam = 1;
							  else  dam = 0;
							  if (cur_game->comp_posible_steps[1][cur_game->c_step.pos]!=7)
							  cur_game->mtx[cur_game->comp_posible_steps[0][cur_game->c_step.pos]][cur_game->comp_posible_steps[1][cur_game->c_step.pos]] = cur_game->mtx[cur_game->c_step.x0][cur_game->c_step.y0];
							  else
							  {
								  cur_game->mtx[cur_game->comp_posible_steps[0][cur_game->c_step.pos]][cur_game->comp_posible_steps[1][cur_game->c_step.pos]] = 'd';
								  dam = 1;
							  }
							  cur_game->mtx[cur_game->c_step.x0][cur_game->c_step.y0] = '0';
							  move_black_shashka(cur_game->c_step.x0, cur_game->c_step.y0, cur_game->c_step.pos, dam, cur_game->c_step.beat);
						  if (beat == 1)
						  {
							  cur_game->find_comp_possible_steps(cur_game->mtx, cur_game->comp_posible_steps[0][cur_game->c_step.pos], cur_game->comp_posible_steps[1][cur_game->c_step.pos], beat);
							  if (beat == 1)
							  {
								  do_comp_step(beat, cur_game->comp_posible_steps[0][cur_game->c_step.pos], cur_game->comp_posible_steps[1][cur_game->c_step.pos]);
							  }
							  else client_turn = true;
						  }
						  else client_turn = true;
					  }
		 }


		 private: Void doing_step(int i,int j)
		 {
					  if (client_turn)
					  {
							  if (cells_lighted)
							  {
								  int b;
								  cur_game->find_possible_steps(cur_game->mtx, choosen_x, choosen_y, b);
								  light_cells( false);
								  cells_lighted = false;
							  }
							  int beat;
							  beat_client = if_beat();
								  if (!shashka_choosen)
								  {
									  if (cur_game->mtx[i][j] == 'w' || cur_game->mtx[i][j] == 'q')
									  {
										  cur_num = cur_game->find_possible_steps(cur_game->mtx, i, j, beat);
										  if (cur_num > 0 && beat==beat_client)
										  {
											  shashka_choosen = true;
											  choosen_x = i; choosen_y = j;
											  beat_client = beat;
											  light_cells(true);
											  cells_lighted = true;
										  }
									  }
								  }
								  else
								  {
									  cur_num = cur_game->find_possible_steps(cur_game->mtx, choosen_x, choosen_y, beat);
									  int s = is_step(i, j, cur_num);
									  if (s!=-1)
									  {
										  int dam;
										  if (cur_game->mtx[choosen_x][choosen_y] == 'q' || j == 0)  dam = 1;
										  else   dam = 0; 
										  beat = beat_client;
										  move_white_shashka(choosen_x, choosen_y, s, dam,beat);
										  shashka_choosen = false;
										  cur_game->mtx[choosen_x][choosen_y] = '0';
										  if (dam == 0)
											  cur_game->mtx[i][j] = 'w';
										  else cur_game->mtx[i][j] = 'q';
										  if (beat_client == 0) client_turn = false;
										  else 
										  { 
											  cur_num = cur_game->find_possible_steps(cur_game->mtx, i, j, beat);
											  if (beat > 0)
											  {
												  choosen_x = i; choosen_y = j;
												  shashka_choosen = true;
												  beat_client = beat;
												  light_cells(true);
												  cells_lighted = true;
											  }
											  else client_turn = false;
										  }
									  }
									  else
									  {
										  if (cur_game->mtx[i][j] == 'w' || cur_game->mtx[i][j] == 'q')
										  { cur_num = cur_game->find_possible_steps(cur_game->mtx, i, j, beat);
										  if (cur_num > 0 && beat==beat_client)
										  {
											  shashka_choosen = true;
											  choosen_x = i; choosen_y = j;
											  beat_client = beat;
											  light_cells( true);
											  cells_lighted = true;
										  }
									  }
								  }
						  }
					  }
		 }
				  private: int if_beat()
				  {
							   int res = 0;
							   int beat = 0; int col_st = 0;
							   for (int i = 0; i < 8; i++)
							   {
								   for (int j = 0; j < 8; j++)
								   {
									   if (cur_game->mtx[i][j] == 'w' || cur_game->mtx[i][j] == 'q')
									   {
										   col_st+=cur_game->find_possible_steps(cur_game->mtx, i, j, beat);
										   if (beat == 1) res = 1;
									   }
								   }
							   }
							   return res;
				  }

				  private: int is_step(int x, int y,int n)
				  {
							   int flag = -1;
							   for (int i = 0; i < n; i++)
							   {
								   if (cur_game->posible_steps[0][i] == x && cur_game->posible_steps[1][i] == y)
									   flag = i;
							   }
							   return flag;
				  }


private: System::Void startNewGameToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Application::Restart();
}
};
}
