#pragma once

#include <windows.h>
#include <cmath>
#include "Extern.h"

namespace Clicker
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ClickerForm
	/// </summary>
	public ref class ClickerForm : public System::Windows::Forms::Form
	{
	public:
		Point currentMousePos;
		bool headerMouseDown;

		ClickerForm(void)
		{
			InitializeComponent();
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ClickerForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ header;
	private: System::Windows::Forms::Button^ exit_btn;
	private: System::Windows::Forms::TrackBar^ minimumSlider;
	private: System::Windows::Forms::TrackBar^ maximumSlider;


	private: System::Windows::Forms::Label^ Minimum;
	private: System::Windows::Forms::Label^ Maximum;
	private: System::Windows::Forms::Label^ DisplayMinimum;
	private: System::Windows::Forms::Label^ DisplayMaximum;
	private: System::Windows::Forms::Label^ label1;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ClickerForm::typeid));
			this->header = (gcnew System::Windows::Forms::Panel());
			this->exit_btn = (gcnew System::Windows::Forms::Button());
			this->minimumSlider = (gcnew System::Windows::Forms::TrackBar());
			this->maximumSlider = (gcnew System::Windows::Forms::TrackBar());
			this->Minimum = (gcnew System::Windows::Forms::Label());
			this->Maximum = (gcnew System::Windows::Forms::Label());
			this->DisplayMinimum = (gcnew System::Windows::Forms::Label());
			this->DisplayMaximum = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->header->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minimumSlider))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maximumSlider))->BeginInit();
			this->SuspendLayout();
			// 
			// header
			// 
			this->header->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->header->Controls->Add(this->exit_btn);
			this->header->ForeColor = System::Drawing::SystemColors::AppWorkspace;
			this->header->Location = System::Drawing::Point(-8, 0);
			this->header->Name = L"header";
			this->header->Size = System::Drawing::Size(737, 40);
			this->header->TabIndex = 26;
			this->header->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ClickerForm::header_MouseDown);
			this->header->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &ClickerForm::header_MouseUp);
			this->header->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &ClickerForm::header_MouseMove);
			// 
			// exit
			// 
			this->exit_btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exit.BackgroundImage")));
			this->exit_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->exit_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->exit_btn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->exit_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exit_btn->Location = System::Drawing::Point(306, 12);
			this->exit_btn->Name = L"exit";
			this->exit_btn->Size = System::Drawing::Size(15, 15);
			this->exit_btn->TabIndex = 2;
			this->exit_btn->UseVisualStyleBackColor = true;
			this->exit_btn->Click += gcnew System::EventHandler(this, &ClickerForm::exit_click);
			// 
			// minimumSlider
			// 
			this->minimumSlider->Location = System::Drawing::Point(120, 46);
			this->minimumSlider->Maximum = 30;
			this->minimumSlider->Minimum = 1;
			this->minimumSlider->Name = L"minimumSlider";
			this->minimumSlider->Size = System::Drawing::Size(119, 45);
			this->minimumSlider->TabIndex = 30;
			this->minimumSlider->TickStyle = System::Windows::Forms::TickStyle::None;
			this->minimumSlider->Value = 10;
			this->minimumSlider->ValueChanged += gcnew System::EventHandler(this, &ClickerForm::minimum_slider_value_change);
			// 
			// maximumSlider
			// 
			this->maximumSlider->Location = System::Drawing::Point(120, 97);
			this->maximumSlider->Maximum = 30;
			this->maximumSlider->Minimum = 1;
			this->maximumSlider->Name = L"maximumSlider";
			this->maximumSlider->Size = System::Drawing::Size(119, 45);
			this->maximumSlider->TabIndex = 31;
			this->maximumSlider->TickStyle = System::Windows::Forms::TickStyle::None;
			this->maximumSlider->Value = 14;
			this->maximumSlider->ValueChanged += gcnew System::EventHandler(this, &ClickerForm::maximum_slider_value_change);
			// 
			// Minimum
			// 
			this->Minimum->AutoSize = true;
			this->Minimum->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Minimum->ForeColor = System::Drawing::SystemColors::AppWorkspace;
			this->Minimum->Location = System::Drawing::Point(19, 40);
			this->Minimum->Name = L"Minimum";
			this->Minimum->Size = System::Drawing::Size(102, 30);
			this->Minimum->TabIndex = 32;
			this->Minimum->Text = L"Minimum";
			// 
			// Maximum
			// 
			this->Maximum->AutoSize = true;
			this->Maximum->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Maximum->ForeColor = System::Drawing::SystemColors::AppWorkspace;
			this->Maximum->Location = System::Drawing::Point(19, 88);
			this->Maximum->Name = L"Maximum";
			this->Maximum->Size = System::Drawing::Size(106, 30);
			this->Maximum->TabIndex = 33;
			this->Maximum->Text = L"Maximum";
			// 
			// DisplayMinimum
			// 
			this->DisplayMinimum->AutoSize = true;
			this->DisplayMinimum->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DisplayMinimum->ForeColor = System::Drawing::SystemColors::AppWorkspace;
			this->DisplayMinimum->Location = System::Drawing::Point(245, 40);
			this->DisplayMinimum->Name = L"DisplayMinimum";
			this->DisplayMinimum->Size = System::Drawing::Size(35, 30);
			this->DisplayMinimum->TabIndex = 34;
			this->DisplayMinimum->Text = L"10";
			// 
			// DisplayMaximum
			// 
			this->DisplayMaximum->AutoSize = true;
			this->DisplayMaximum->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DisplayMaximum->ForeColor = System::Drawing::SystemColors::AppWorkspace;
			this->DisplayMaximum->Location = System::Drawing::Point(245, 88);
			this->DisplayMaximum->Name = L"DisplayMaximum";
			this->DisplayMaximum->Size = System::Drawing::Size(35, 30);
			this->DisplayMaximum->TabIndex = 35;
			this->DisplayMaximum->Text = L"14";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::AppWorkspace;
			this->label1->Location = System::Drawing::Point(89, 134);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(117, 30);
			this->label1->TabIndex = 36;
			this->label1->Text = L"Toggle: F10";
			// 
			// ClickerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(34)));
			this->ClientSize = System::Drawing::Size(325, 190);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->DisplayMaximum);
			this->Controls->Add(this->DisplayMinimum);
			this->Controls->Add(this->Maximum);
			this->Controls->Add(this->Minimum);
			this->Controls->Add(this->maximumSlider);
			this->Controls->Add(this->minimumSlider);
			this->Controls->Add(this->header);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ClickerForm";
			this->header->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minimumSlider))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maximumSlider))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
		private: void minimum_slider_value_change(System::Object^, System::EventArgs^)
		{
			if (this->minimumSlider->Value > this->maximumSlider->Value)
			{
				this->maximumSlider->Value = this->minimumSlider->Value;
				Extern::set_max_cps(Extern::MouseButton::left, this->maximumSlider->Value);
				this->DisplayMaximum->Text = this->maximumSlider->Value.ToString();
			}
			Extern::set_min_cps(Extern::MouseButton::left, this->minimumSlider->Value);
			this->DisplayMinimum->Text = this->minimumSlider->Value.ToString();
		}
		private: void maximum_slider_value_change(System::Object^, System::EventArgs^)
		{
			if (this->maximumSlider->Value < this->minimumSlider->Value)
			{
				this->minimumSlider->Value = this->maximumSlider->Value;
				Extern::set_min_cps(Extern::MouseButton::left, this->minimumSlider->Value);
				this->DisplayMinimum->Text = this->minimumSlider->Value.ToString();
			}
			Extern::set_max_cps(Extern::MouseButton::left, this->maximumSlider->Value);
			this->DisplayMaximum->Text = this->maximumSlider->Value.ToString();
		}

		private: void exit_click(System::Object^, System::EventArgs^)
		{
			exit(0);
		}

		private: System::Void header_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			headerMouseDown = true;
			currentMousePos = Point(e->X, e->Y);
		}
		private: System::Void header_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			headerMouseDown = false;
		}
		private: System::Void header_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (headerMouseDown) {
				Point currentScreenPos = PointToScreen(e->Location);
				Location = Point(currentScreenPos.X - currentMousePos.X, currentScreenPos.Y - currentMousePos.Y);
			}
}
};
}
