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
			this->SuspendLayout();
			// 
			// game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(930, 864);
			this->Name = L"game";
			this->Text = L"game";
			this->Load += gcnew System::EventHandler(this, &game::game_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &game::game_Paint);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &game::game_MouseClick);
			this->ResumeLayout(false);

			
		}
#pragma endregion
		int pos_board_x = 37;
		int pos_board_y = 94;
		int board_w = 720;
		int board_h = 720;
		Graphics^ board;
		current_positions *cur_game = new current_positions();
	private: System::Void game_Load(System::Object^  sender, System::EventArgs^  e) 
	{
				 game::BackColor = Color::OliveDrab;
				 board = this->CreateGraphics();
				 
	}
	private: bool light_cells(int x, int y, bool on_off)
	{
				 return true;
	}

	private: Void move_white_shashka(int x0, int y0, int x, int y,int dam)
	{
				 System::Drawing::Brush^ cells_black = gcnew SolidBrush(Color::Tan);
				 board->FillRectangle(cells_black, board_w / 8 * x0+pos_board_x, board_h / 8 * y0+pos_board_y, board_w / 8, board_h / 8);
                 draw_white_shashka(x, y, dam);
				 board->DrawRectangle(System::Drawing::Pens::Black, pos_board_x, pos_board_y, board_w - 1, board_h - 1);
	}
	private: Void move_black_shashka(int x0, int y0, int x, int y, int dam)
	{
				 System::Drawing::Brush^ cells_black = gcnew SolidBrush(Color::Tan);
				 board->FillRectangle(cells_black, board_w / 8 * x0+pos_board_x, board_h / 8 * y0+pos_board_y, board_w / 8, board_h / 8);
				 draw_black_shashka(x, y, dam);
				 board->DrawRectangle(System::Drawing::Pens::Black, pos_board_x, pos_board_y, board_w - 1, board_h - 1);
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
private: System::Void game_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 int flag;
			 int col = cur_game->find_possible_steps(2, 5, flag);
}
};
}
