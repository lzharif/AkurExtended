#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <cvToBitmap.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#define CLOCK_PER_SEC 1000;

using namespace cv;
cv::VideoCapture video;
cv::Mat CitraAwal, CitraOlah, CitraOlah2, CitraHasil, frameDigitTemplate[22], frameDigitTemplateF[22], CitraMask;
cv::String alamatFolder;
int banyakCitra, korelasi[4], iCitra, widthDigit, heightDigit, statusGanti, metode, algoritma, pilihAlgoritma;
FILE *outfile;

struct datalog{
	double avgf;
	double avgm;
	double avgd;
	double avgs;
};

struct datalog *ptr, logs[20000];

namespace UjiKenalDigit {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	protected: 
	protected: 
	protected:
	protected:
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::Button^  buttonOlahBanyak;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog;

	private: System::Windows::Forms::Button^  buttonCariBatas;
	private: System::Windows::Forms::Button^  buttonBuatTemplate;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBoxBatasPikselPutih;

	private: System::Windows::Forms::Label^  label7;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  buttonOlahTM;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label8;

	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->buttonOlahBanyak = (gcnew System::Windows::Forms::Button());
			this->folderBrowserDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->buttonCariBatas = (gcnew System::Windows::Forms::Button());
			this->buttonBuatTemplate = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxBatasPikselPutih = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonOlahTM = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog";
			// 
			// buttonOlahBanyak
			// 
			this->buttonOlahBanyak->Location = System::Drawing::Point(19, 221);
			this->buttonOlahBanyak->Name = L"buttonOlahBanyak";
			this->buttonOlahBanyak->Size = System::Drawing::Size(93, 23);
			this->buttonOlahBanyak->TabIndex = 18;
			this->buttonOlahBanyak->Text = L"Uji Algoritma";
			this->buttonOlahBanyak->UseVisualStyleBackColor = true;
			this->buttonOlahBanyak->Click += gcnew System::EventHandler(this, &MyForm::buttonOlahBanyak_Click);
			// 
			// buttonCariBatas
			// 
			this->buttonCariBatas->Location = System::Drawing::Point(19, 90);
			this->buttonCariBatas->Name = L"buttonCariBatas";
			this->buttonCariBatas->Size = System::Drawing::Size(91, 23);
			this->buttonCariBatas->TabIndex = 29;
			this->buttonCariBatas->Text = L"Cari Batas";
			this->buttonCariBatas->UseVisualStyleBackColor = true;
			this->buttonCariBatas->Click += gcnew System::EventHandler(this, &MyForm::buttonCariBatas_Click);
			// 
			// buttonBuatTemplate
			// 
			this->buttonBuatTemplate->Location = System::Drawing::Point(19, 29);
			this->buttonBuatTemplate->Name = L"buttonBuatTemplate";
			this->buttonBuatTemplate->Size = System::Drawing::Size(91, 23);
			this->buttonBuatTemplate->TabIndex = 30;
			this->buttonBuatTemplate->Text = L"Buat Template";
			this->buttonBuatTemplate->UseVisualStyleBackColor = true;
			this->buttonBuatTemplate->Click += gcnew System::EventHandler(this, &MyForm::buttonBuatTemplate_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 13);
			this->label1->TabIndex = 31;
			this->label1->Text = L"Langkah 1 :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(16, 132);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(64, 13);
			this->label3->TabIndex = 33;
			this->label3->Text = L"Langkah 3 :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(16, 74);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(64, 13);
			this->label5->TabIndex = 34;
			this->label5->Text = L"Langkah 2 :";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(39, 196);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(37, 13);
			this->label6->TabIndex = 35;
			this->label6->Text = L"atau...";
			// 
			// textBoxBatasPikselPutih
			// 
			this->textBoxBatasPikselPutih->Location = System::Drawing::Point(19, 273);
			this->textBoxBatasPikselPutih->Name = L"textBoxBatasPikselPutih";
			this->textBoxBatasPikselPutih->Size = System::Drawing::Size(83, 20);
			this->textBoxBatasPikselPutih->TabIndex = 36;
			this->textBoxBatasPikselPutih->Text = L"600";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(16, 257);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(149, 13);
			this->label7->TabIndex = 37;
			this->label7->Text = L"Batas perhitungan piksel putih";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(111, 226);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(16, 13);
			this->label9->TabIndex = 39;
			this->label9->Text = L"->";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(111, 166);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(16, 13);
			this->label2->TabIndex = 41;
			this->label2->Text = L"->";
			// 
			// buttonOlahTM
			// 
			this->buttonOlahTM->Location = System::Drawing::Point(19, 161);
			this->buttonOlahTM->Name = L"buttonOlahTM";
			this->buttonOlahTM->Size = System::Drawing::Size(93, 23);
			this->buttonOlahTM->TabIndex = 40;
			this->buttonOlahTM->Text = L"Uji dengan TM";
			this->buttonOlahTM->UseVisualStyleBackColor = true;
			this->buttonOlahTM->Click += gcnew System::EventHandler(this, &MyForm::buttonOlahTM_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(133, 166);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(173, 13);
			this->label4->TabIndex = 42;
			this->label4->Text = L"Kenali semua citra digit dengan TM";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(133, 218);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(188, 26);
			this->label8->TabIndex = 43;
			this->label8->Text = L"Kenali citra digit 1 dengan perhitungan\r\npiksel putih dan 2-4 dengan TM";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(325, 301);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->buttonOlahTM);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBoxBatasPikselPutih);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonBuatTemplate);
			this->Controls->Add(this->buttonCariBatas);
			this->Controls->Add(this->buttonOlahBanyak);
			this->Name = L"MyForm";
			this->Text = L"Aplikasi Uji Algoritma";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		std::string MarshalString(System::String ^ s) {
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			std::string os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
			return os;
		}		

		void olahCitraTemplate() {
			cv::String fileTemplate;
			cv::String fileSimpan;
			cv::Size ukuranFrame1, ukuranFrame2;
			ukuranFrame1 = cv::Size(30,71);
			ukuranFrame2 = cv::Size(12,71);
			for(int metode = 0; metode <= 4; metode++) {
				//Untuk citra template rata-rata
				if (metode < 3) {
					for(int i = 0; i <= 21; i++) {
						for (int d = 1; d <= 3; d++) {
							fileTemplate = "../datatemplateslmrata/s" + std::to_string(i) + "_" + std::to_string(d) + ".jpg";							
							frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);
							if(i > 19)
								cv::resize(frameDigitTemplate[d],frameDigitTemplate[d],ukuranFrame2, 0.0, 0.0, INTER_CUBIC);
							else
								cv::resize(frameDigitTemplate[d],frameDigitTemplate[d],ukuranFrame1, 0.0, 0.0, INTER_CUBIC);
						}

						CitraOlah = (frameDigitTemplate[1] + frameDigitTemplate[2] + frameDigitTemplate[3])/3;
						switch (metode) {
						case 0:
							adaptiveThreshold(CitraOlah,CitraHasil, 255.0, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 199, 0.0);
							fileSimpan = "../slmratabiner/s" + std::to_string(i) + ".jpg";
							break;
						case 1:
							CitraOlah.copyTo(CitraHasil);
							fileSimpan = "../slmratagray/s" + std::to_string(i) + ".jpg";
							break;
						case 2:
							equalizeHist(CitraOlah,CitraHasil);
							fileSimpan = "../slmratagrayekual/s" + std::to_string(i) + ".jpg";
							break;
						}					
						imwrite(fileSimpan,CitraHasil);
					}
				}
				//Untuk citra template satu buah
				else {
					for(int i = 0; i <= 21; i++) {				
						fileTemplate = "../datatemplateslmsatu/s" + std::to_string(i) + "_x.jpg";				
						CitraAwal = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);		
						if(i > 19)
							cv::resize(CitraAwal,CitraOlah,ukuranFrame2, 0.0, 0.0, INTER_CUBIC);
						else
							cv::resize(CitraAwal,CitraOlah,ukuranFrame1, 0.0, 0.0, INTER_CUBIC);					
						switch (metode) {
						case 3:
							fileSimpan = "../slmgray/s" + std::to_string(i) + ".jpg";
							break;
						case 4:
							equalizeHist(CitraOlah,CitraOlah);
							fileSimpan = "../slmgrayekual/s" + std::to_string(i) + ".jpg";
							break;
						}
						imwrite(fileSimpan,CitraOlah);
					}
				}				
			}
		}

		void olahCitraSlmPraPengolahan() {
			cv::Size ukuranFrameKecil, ukuranFrame;
			int l, t, w, h, batasPikselPutih;
			Mat frameDigit[4], frameDigitF[4], matKorelasi;
			batasPikselPutih = Convert::ToInt16(textBoxBatasPikselPutih->Text);
			cvtColor(CitraAwal, CitraOlah, COLOR_BGR2GRAY);
			switch (algoritma) {
			case 1:				
				break;
			case 2:
				equalizeHist(CitraOlah, CitraOlah);
				break;
			case 3:
				equalizeHist(CitraOlah, CitraOlah);
				break;
			case 4:
				equalizeHist(CitraOlah, CitraOlah);
				break;
			case 5:
				equalizeHist(CitraOlah, CitraOlah);
				break;
			case 6:
				equalizeHist(CitraOlah, CitraOlah);
				adaptiveThreshold(CitraOlah,CitraOlah, 255.0, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 499, 0.0);
				break;
			case 7:
				equalizeHist(CitraOlah, CitraOlah);
				adaptiveThreshold(CitraOlah,CitraOlah, 255.0, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 499, 0.0);
				break;
			}			
			//adaptiveThreshold(CitraOlah2,CitraOlah, 255.0, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 199, 0.0);

			//Pemotongan digit-digit citra pada layout CO
			ukuranFrameKecil = cv::Size(12,71);
			ukuranFrame = cv::Size(30,71);
			// Variasi adalah (30,58), (30,52), dan (30,39)
			//Ini layout yang baru

			for (int i = 0; i < 4; i++) {
				if (i == 0) {
					l = (int) (0.153 * CitraOlah.cols);
					t = (int) (0.190 * CitraOlah.rows);
					w = (int) (0.085 * CitraOlah.cols);
					h = (int) (0.490 * CitraOlah.rows);
				} else if (i == 1) {
					l = (int) (0.257 * CitraOlah.cols);
					t = (int) (0.190 * CitraOlah.rows);
					w = (int) (0.178 * CitraOlah.cols);
					h = (int) (0.490 * CitraOlah.rows);
				} else if (i == 2) {
					l = (int) (0.458 * CitraOlah.cols);
					t = (int) (0.190 * CitraOlah.rows);
					w = (int) (0.178 * CitraOlah.cols);
					h = (int) (0.490 * CitraOlah.rows);
				} else if (i == 3) {
					l = (int) (0.670 * CitraOlah.cols);
					t = (int) (0.190 * CitraOlah.rows);
					w = (int) (0.178 * CitraOlah.cols);
					h = (int) (0.490 * CitraOlah.rows);
				}
				//rectangle(CitraOlah, cv::Point(l, t), cv::Point(l + w, t + h), cv::Scalar(0, 255, 255), +1);
				Rect kotakDigit = Rect(l, t, w, h);				
				if(i==0) {
					frameDigit[i] = Mat(CitraOlah, kotakDigit);
					resize(frameDigit[i], frameDigit[i], ukuranFrameKecil, 0.0, 0.0, INTER_CUBIC); //Untuk digit pertama
				}
				else {
					frameDigit[i] = Mat(CitraOlah, kotakDigit);
					resize(frameDigit[i], frameDigit[i], ukuranFrame, 0.0, 0.0, INTER_CUBIC); //Untuk digit kedua hingga keempat
				}

				//Mulai pengolahan

				//equalizeHist(frameDigit[i], frameDigit[i]);
				//adaptiveThreshold(frameDigit[i], frameDigit[i], 255.0, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 499, 0.0);
				frameDigit[i].convertTo(frameDigitF[i], CV_32F);
			}

			for (int i = 0; i < 4; i++) {
				double kmax = -1;
				if (i == 0) {					
					if (algoritma < 6)
						adaptiveThreshold(frameDigit[i], frameDigit[i], 255.0, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 499, 0.0);
					cv::String nama = "Citra";
					imshow(nama, frameDigit[i]);			
					int pikselPutih = countNonZero(frameDigit[i]);
					//23-11-2015 Coba ganti ke inverse
					if (pikselPutih < batasPikselPutih)
						korelasi[i] = 1;
					else
						korelasi[i] = 0;
				}
				else {
					for (int d = 0; d <= 19; d++) {				
						matchTemplate(frameDigitF[i], frameDigitTemplateF[d], matKorelasi, TM_CCOEFF_NORMED);
						double k = matKorelasi.at<float>(0,0);
						if (k > kmax) {
							kmax = k;						
							korelasi[i] = d % 10;
						}
					}
				}				
			}									
			fprintf(outfile, "%d\t%d\t%d\t%d\t%d\n", iCitra, korelasi[0], korelasi[1], korelasi[2], korelasi[3]);
		}

		void olahCitraSlmKlasifikasiDigit() {			
			cv::Size ukuranFrameKecil, ukuranFrame;
			int l, t, w, h, batasPikselPutih;
			Mat frameDigit[4], frameDigitF[4], matKorelasi;
			batasPikselPutih = Convert::ToInt16(textBoxBatasPikselPutih->Text);
			cvtColor(CitraAwal, CitraOlah, COLOR_BGR2GRAY);
			switch (pilihAlgoritma) {
			case 1:				
				break;
			case 2:
				equalizeHist(CitraOlah, CitraOlah);
				break;
			case 3:
				equalizeHist(CitraOlah, CitraOlah);
				break;
			case 4:
				equalizeHist(CitraOlah, CitraOlah);
				break;
			case 5:
				equalizeHist(CitraOlah, CitraOlah);
				break;
			case 6:
				equalizeHist(CitraOlah, CitraOlah);
				adaptiveThreshold(CitraOlah,CitraOlah, 255.0, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 499, 0.0);
				break;
			case 7:
				equalizeHist(CitraOlah, CitraOlah);
				adaptiveThreshold(CitraOlah,CitraOlah, 255.0, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 499, 0.0);
				break;
			}			

			ukuranFrameKecil = cv::Size(12,71);
			ukuranFrame = cv::Size(30,71);			

			for (int i = 0; i < 4; i++) {
				if (i == 0) {
					l = (int) (0.153 * CitraOlah.cols);
					t = (int) (0.190 * CitraOlah.rows);
					w = (int) (0.085 * CitraOlah.cols);
					h = (int) (0.490 * CitraOlah.rows);
				} else if (i == 1) {
					l = (int) (0.257 * CitraOlah.cols);
					t = (int) (0.190 * CitraOlah.rows);
					w = (int) (0.178 * CitraOlah.cols);
					h = (int) (0.490 * CitraOlah.rows);
				} else if (i == 2) {
					l = (int) (0.458 * CitraOlah.cols);
					t = (int) (0.190 * CitraOlah.rows);
					w = (int) (0.178 * CitraOlah.cols);
					h = (int) (0.490 * CitraOlah.rows);
				} else if (i == 3) {
					l = (int) (0.670 * CitraOlah.cols);
					t = (int) (0.190 * CitraOlah.rows);
					w = (int) (0.178 * CitraOlah.cols);
					h = (int) (0.490 * CitraOlah.rows);
				}				
				Rect kotakDigit = Rect(l, t, w, h);				
				if(i==0) {
					frameDigit[i] = Mat(CitraOlah, kotakDigit);
					resize(frameDigit[i], frameDigit[i], ukuranFrameKecil, 0.0, 0.0, INTER_CUBIC); //Untuk digit pertama
				}
				else {
					frameDigit[i] = Mat(CitraOlah, kotakDigit);
					resize(frameDigit[i], frameDigit[i], ukuranFrame, 0.0, 0.0, INTER_CUBIC); //Untuk digit kedua hingga keempat
				}			
				frameDigit[i].convertTo(frameDigitF[i], CV_32F);
			}

			for (int i = 0; i < 4; i++) {
				double kmax = -1;
				double kmin = 100;
				if (i == 0) {	
					if (pilihAlgoritma < 6)
						adaptiveThreshold(frameDigit[i], frameDigit[i], 255.0, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 499, 0.0);
					cv::String nama = "Citra";
					imshow(nama, frameDigit[i]);			
					int pikselPutih = countNonZero(frameDigit[i]);					
					if (pikselPutih < batasPikselPutih)
						korelasi[i] = 1;
					else
						korelasi[i] = 0;
				}
				else {
					for (int d = 0; d <= 19; d++) {						
						switch(metode)	{
						case 1:
							matchTemplate(frameDigitF[i], frameDigitTemplateF[d], matKorelasi, TM_SQDIFF);
							break;
						case 2:
							matchTemplate(frameDigitF[i], frameDigitTemplateF[d], matKorelasi, TM_SQDIFF_NORMED);
							break;
						case 3:
							matchTemplate(frameDigitF[i], frameDigitTemplateF[d], matKorelasi, TM_CCORR);
							break;
						case 4:
							matchTemplate(frameDigitF[i], frameDigitTemplateF[d], matKorelasi, TM_CCORR_NORMED);
							break;
						case 5:
							matchTemplate(frameDigitF[i], frameDigitTemplateF[d], matKorelasi, TM_CCOEFF);
							break;
						case 6:
							matchTemplate(frameDigitF[i], frameDigitTemplateF[d], matKorelasi, TM_CCOEFF_NORMED);
							break;
						}
						if (metode < 3) {
							double k = matKorelasi.at<float>(0,0);
							if (k < kmin) {
								kmin = k;						
								korelasi[i] = d % 10;
							}
						}
						else {
							double k = matKorelasi.at<float>(0,0);
							if (k > kmax) {
								kmax = k;						
								korelasi[i] = d % 10;
							}
						}

					}
				}				
			}									
			fprintf(outfile, "%d\t%d\t%d\t%d\t%d\n", iCitra, korelasi[0], korelasi[1], korelasi[2], korelasi[3]);
		}

		void olahCitra(int algoritmaPraPengolahan, int algoritmaKlasifikasi, int jenisOlah) {
			cv::Size ukuranFrameKecil, ukuranFrame;
			int l, t, w, h, batasPikselPutih, penandaDigit1 = 0;
			Mat frameDigit[4], frameDigitF[4], matKorelasi;
			batasPikselPutih = Convert::ToInt16(textBoxBatasPikselPutih->Text);
			cvtColor(CitraAwal, CitraOlah, COLOR_BGR2GRAY);
			int banyakPengulangan;
			//jenisOlah 1 tandanya pakai TM semua, kalau 2 tandanya hanya digit 2-4 yg pakai TM
			if (jenisOlah == 1)
				banyakPengulangan = 21;
			else
				banyakPengulangan = 19;
			switch (algoritmaPraPengolahan) {
			case 1:				
				break;
			case 2:
				equalizeHist(CitraOlah, CitraOlah);
				break;
			case 3:
				equalizeHist(CitraOlah, CitraOlah);
				break;
			case 4:
				equalizeHist(CitraOlah, CitraOlah);
				break;
			case 5:
				equalizeHist(CitraOlah, CitraOlah);
				break;
			case 6:
				equalizeHist(CitraOlah, CitraOlah);
				adaptiveThreshold(CitraOlah,CitraOlah, 255.0, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 499, 0.0);
				break;
			case 7:
				equalizeHist(CitraOlah, CitraOlah);
				adaptiveThreshold(CitraOlah,CitraOlah, 255.0, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 499, 0.0);
				break;
			}			
			//adaptiveThreshold(CitraOlah2,CitraOlah, 255.0, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 199, 0.0);

			//Pemotongan digit-digit citra pada layout CO
			ukuranFrameKecil = cv::Size(12,71);
			ukuranFrame = cv::Size(30,71);
			// Variasi adalah (30,58), (30,52), dan (30,39)
			//Ini layout yang baru

			for (int i = 0; i < 4; i++) {
				if (i == 0) {
					l = (int) (0.153 * CitraOlah.cols);
					t = (int) (0.190 * CitraOlah.rows);
					w = (int) (0.085 * CitraOlah.cols);
					h = (int) (0.490 * CitraOlah.rows);
				} else if (i == 1) {
					l = (int) (0.257 * CitraOlah.cols);
					t = (int) (0.190 * CitraOlah.rows);
					w = (int) (0.178 * CitraOlah.cols);
					h = (int) (0.490 * CitraOlah.rows);
				} else if (i == 2) {
					l = (int) (0.458 * CitraOlah.cols);
					t = (int) (0.190 * CitraOlah.rows);
					w = (int) (0.178 * CitraOlah.cols);
					h = (int) (0.490 * CitraOlah.rows);
				} else if (i == 3) {
					l = (int) (0.670 * CitraOlah.cols);
					t = (int) (0.190 * CitraOlah.rows);
					w = (int) (0.178 * CitraOlah.cols);
					h = (int) (0.490 * CitraOlah.rows);
				}
				//rectangle(CitraOlah, cv::Point(l, t), cv::Point(l + w, t + h), cv::Scalar(0, 255, 255), +1);
				Rect kotakDigit = Rect(l, t, w, h);				
				if(i==0) {
					frameDigit[i] = Mat(CitraOlah, kotakDigit);
					resize(frameDigit[i], frameDigit[i], ukuranFrameKecil, 0.0, 0.0, INTER_CUBIC); //Untuk digit pertama
				}
				else {
					frameDigit[i] = Mat(CitraOlah, kotakDigit);
					resize(frameDigit[i], frameDigit[i], ukuranFrame, 0.0, 0.0, INTER_CUBIC); //Untuk digit kedua hingga keempat
				}

				//Mulai pengolahan

				//equalizeHist(frameDigit[i], frameDigit[i]);
				//adaptiveThreshold(frameDigit[i], frameDigit[i], 255.0, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 499, 0.0);
				frameDigit[i].convertTo(frameDigitF[i], CV_32F);
			}

			for (int i = 0; i < 4; i++) {
				double kmax = -1;
				double kmin = 1000000000000000000;
				if (jenisOlah == 2) {
					if (i == 0) {					
						if (algoritmaPraPengolahan < 6)
							adaptiveThreshold(frameDigit[i], frameDigit[i], 255.0, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 499, 0.0);
						cv::String nama = "Citra";
						imshow(nama, frameDigit[i]);			
						int pikselPutih = countNonZero(frameDigit[i]);
						//23-11-2015 Coba ganti ke inverse
						if (pikselPutih < batasPikselPutih)
							korelasi[i] = 1;
						else
							korelasi[i] = 0;
						penandaDigit1 = 1;
					}
				}
				if(penandaDigit1 == 0) {
					if (i==0) {
						for (int d = 20; d <= 21; d++) {					
							switch(algoritmaKlasifikasi)	{
							case 1:
								matchTemplate(frameDigitF[i], frameDigitTemplateF[d], matKorelasi, TM_SQDIFF);
								break;
							case 2:
								matchTemplate(frameDigitF[i], frameDigitTemplateF[d], matKorelasi, TM_SQDIFF_NORMED);
								break;
							case 3:
								matchTemplate(frameDigitF[i], frameDigitTemplateF[d], matKorelasi, TM_CCORR);
								break;
							case 4:
								matchTemplate(frameDigitF[i], frameDigitTemplateF[d], matKorelasi, TM_CCORR_NORMED);
								break;
							case 5:
								matchTemplate(frameDigitF[i], frameDigitTemplateF[d], matKorelasi, TM_CCOEFF);
								break;
							case 6:
								matchTemplate(frameDigitF[i], frameDigitTemplateF[d], matKorelasi, TM_CCOEFF_NORMED);
								break;
							}
							if (algoritmaKlasifikasi < 3) {
								double k = 0;
								k = matKorelasi.at<float>(0,0);
								if (k < kmin) {
									kmin = k;						
									korelasi[i] = d % 20;
								}
							}
							else {
								double k = 0;
								k = matKorelasi.at<float>(0,0);
								if (k > kmax) {
									kmax = k;						
									korelasi[i] = d % 20;
								}
							}
						}
					}
					else {
						for (int d = 0; d <= 19; d++) {					
							switch(algoritmaKlasifikasi)	{
							case 1:
								matchTemplate(frameDigitF[i], frameDigitTemplateF[d], matKorelasi, TM_SQDIFF);
								break;
							case 2:
								matchTemplate(frameDigitF[i], frameDigitTemplateF[d], matKorelasi, TM_SQDIFF_NORMED);
								break;
							case 3:
								matchTemplate(frameDigitF[i], frameDigitTemplateF[d], matKorelasi, TM_CCORR);
								break;
							case 4:
								matchTemplate(frameDigitF[i], frameDigitTemplateF[d], matKorelasi, TM_CCORR_NORMED);
								break;
							case 5:
								matchTemplate(frameDigitF[i], frameDigitTemplateF[d], matKorelasi, TM_CCOEFF);
								break;
							case 6:
								matchTemplate(frameDigitF[i], frameDigitTemplateF[d], matKorelasi, TM_CCOEFF_NORMED);
								break;
							}
							if (algoritmaKlasifikasi < 3) {
								double k = 0;
								k=matKorelasi.at<float>(0,0);
								if (k < kmin) {
									kmin = k;						
									korelasi[i] = d % 10;
								}
							}
							else {
								double k = 0;
								k = matKorelasi.at<float>(0,0);
								if (k > kmax) {
									kmax = k;						
									korelasi[i] = d % 10;
								}
							}
						}	
					}
				}
				penandaDigit1 = 0;
			}									
			fprintf(outfile, "%d\t%d\t%d\t%d\t%d\n", iCitra, korelasi[0], korelasi[1], korelasi[2], korelasi[3]);
		}

	private: System::Void buttonOlahBanyak_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (folderBrowserDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
					 int jenisOlah = 2;
					 int algoritmaPraPengolahan, algoritmaKlasifikasi;
					 cv::String fileTemplate;
					 for (algoritmaPraPengolahan = 1; algoritmaPraPengolahan <= 7; algoritmaPraPengolahan++) {
						 for (algoritmaKlasifikasi = 1; algoritmaKlasifikasi <= 6; algoritmaKlasifikasi++) {
							 switch (algoritmaPraPengolahan) {
							 case 1:
								 for (int d = 0; d <= 19; d++) {
									 fileTemplate = "../slmratabiner/s" + std::to_string(d) + ".jpg";								 
									 frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);
									 equalizeHist(frameDigitTemplate[d], frameDigitTemplate[d]);
									 frameDigitTemplate[d].convertTo(frameDigitTemplateF[d], CV_32F);
								 }
								 break;
							 case 2:
								 for (int d = 0; d <= 19; d++) {
									 fileTemplate = "../slmratabiner/s" + std::to_string(d) + ".jpg";
									 frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);
									 equalizeHist(frameDigitTemplate[d], frameDigitTemplate[d]);
									 frameDigitTemplate[d].convertTo(frameDigitTemplateF[d], CV_32F);
								 }
								 break;
							 case 3:
								 for (int d = 0; d <= 19; d++) {
									 fileTemplate = "../slmratagray/s" + std::to_string(d) + ".jpg";								 
									 frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);
									 equalizeHist(frameDigitTemplate[d], frameDigitTemplate[d]);
									 frameDigitTemplate[d].convertTo(frameDigitTemplateF[d], CV_32F);
								 }
								 break;
							 case 4:
								 for (int d = 0; d <= 19; d++) {
									 fileTemplate = "../slmratagrayekual/s" + std::to_string(d) + ".jpg";								 
									 frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);								 		
									 equalizeHist(frameDigitTemplate[d], frameDigitTemplate[d]);
									 frameDigitTemplate[d].convertTo(frameDigitTemplateF[d], CV_32F);
								 }
								 break;
							 case 5:
								 for (int d = 0; d <= 19; d++) {
									 fileTemplate = "../slmgray/s" + std::to_string(d) + ".jpg";								
									 frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);								 				
									 equalizeHist(frameDigitTemplate[d], frameDigitTemplate[d]);
									 frameDigitTemplate[d].convertTo(frameDigitTemplateF[d], CV_32F);
								 }
								 break;
							 case 6:
								 for (int d = 0; d <= 19; d++) {
									 fileTemplate = "../slmgrayekual/s" + std::to_string(d) + ".jpg";								
									 frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);								 				
									 equalizeHist(frameDigitTemplate[d], frameDigitTemplate[d]);
									 frameDigitTemplate[d].convertTo(frameDigitTemplateF[d], CV_32F);
								 }
								 break;
							 case 7:
								 for (int d = 0; d <= 19; d++) {
									 fileTemplate = "../slmratabiner/s" + std::to_string(d) + ".jpg";								
									 frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);								 				
									 equalizeHist(frameDigitTemplate[d], frameDigitTemplate[d]);
									 frameDigitTemplate[d].convertTo(frameDigitTemplateF[d], CV_32F);
								 }
								 break;
							 }

							 statusGanti = 0;
							 //}

							 System::String^ alamatFoldera;
							 alamatFoldera = folderBrowserDialog->SelectedPath;
							 alamatFolder = MarshalString(folderBrowserDialog->SelectedPath);
							 banyakCitra = System::IO::Directory::GetFiles(alamatFoldera)->Length;

							 char namaOutfile[60];
							 sprintf(namaOutfile, "DataPerformaOCR Algoritma %d_%d.txt", algoritmaPraPengolahan, algoritmaKlasifikasi);
							 outfile = fopen(namaOutfile, "w");
							 ptr = &logs[0];
							 fprintf(outfile, "No Citra\td1\td2\td3\td4\n");
							 //fprintf(outfile, "No Citra\td1\td2\td3\td4\td5\td6\n");

							 for(iCitra = 1; iCitra < banyakCitra +1; iCitra++) {
								 //char fileCitraOlah[100];						 
								 cv::String teslagi = alamatFolder + "\\" + std::to_string(iCitra) + ".jpg";
								 CitraAwal = imread(alamatFolder + "\\" + std::to_string(iCitra) + ".jpg");
								 olahCitra(algoritmaPraPengolahan, algoritmaKlasifikasi, jenisOlah);
								 //olahCitraSlmPraPengolahan();
							 }						 
							 fclose(outfile);
						 }
					 }
				 }

			 }
	private: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 widthDigit = 30;
				 heightDigit = 58;
				 statusGanti = 1;
				 pilihAlgoritma = 1;
			 }

	private: System::Void buttonOlahKlasifikasi_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (folderBrowserDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
					 cv::String fileTemplate;					 
					 switch (pilihAlgoritma) {
					 case 1:
						 for (int d = 0; d <= 19; d++) {
							 fileTemplate = "../slmratabiner/s" + std::to_string(d) + ".jpg";								 
							 frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);								 	
							 equalizeHist(frameDigitTemplate[d], frameDigitTemplate[d]);
							 frameDigitTemplate[d].convertTo(frameDigitTemplateF[d], CV_32F);
						 }
						 break;
					 case 2:
						 for (int d = 0; d <= 19; d++) {
							 fileTemplate = "../slmratabiner/s" + std::to_string(d) + ".jpg";
							 frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);								 			
							 equalizeHist(frameDigitTemplate[d], frameDigitTemplate[d]);
							 frameDigitTemplate[d].convertTo(frameDigitTemplateF[d], CV_32F);
						 }
						 break;
					 case 3:
						 for (int d = 0; d <= 19; d++) {
							 fileTemplate = "../slmratagray/s" + std::to_string(d) + ".jpg";								 
							 frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);								 				
							 equalizeHist(frameDigitTemplate[d], frameDigitTemplate[d]);
							 frameDigitTemplate[d].convertTo(frameDigitTemplateF[d], CV_32F);
						 }
						 break;
					 case 4:
						 for (int d = 0; d <= 19; d++) {
							 fileTemplate = "../slmratagrayekual/s" + std::to_string(d) + ".jpg";								 
							 frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);								 		
							 equalizeHist(frameDigitTemplate[d], frameDigitTemplate[d]);
							 frameDigitTemplate[d].convertTo(frameDigitTemplateF[d], CV_32F);
						 }
						 break;
					 case 5:
						 for (int d = 0; d <= 19; d++) {
							 fileTemplate = "../slmgray/s" + std::to_string(d) + ".jpg";								
							 frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);								 				
							 equalizeHist(frameDigitTemplate[d], frameDigitTemplate[d]);
							 frameDigitTemplate[d].convertTo(frameDigitTemplateF[d], CV_32F);
						 }
						 break;
					 case 6:
						 for (int d = 0; d <= 19; d++) {
							 fileTemplate = "../slmgrayekual/s" + std::to_string(d) + ".jpg";								
							 frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);								 				
							 equalizeHist(frameDigitTemplate[d], frameDigitTemplate[d]);
							 frameDigitTemplate[d].convertTo(frameDigitTemplateF[d], CV_32F);
						 }
						 break;
					 case 7:
						 for (int d = 0; d <= 19; d++) {
							 fileTemplate = "../slmratabiner/s" + std::to_string(d) + ".jpg";								
							 frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);								 				
							 equalizeHist(frameDigitTemplate[d], frameDigitTemplate[d]);
							 frameDigitTemplate[d].convertTo(frameDigitTemplateF[d], CV_32F);
						 }
						 break;
					 }

					 statusGanti = 0;
					 //}

					 System::String^ alamatFoldera;
					 alamatFoldera = folderBrowserDialog->SelectedPath;
					 alamatFolder = MarshalString(folderBrowserDialog->SelectedPath);
					 banyakCitra = System::IO::Directory::GetFiles(alamatFoldera)->Length;

					 for(metode = 1; metode <= 6; metode++) {
						 char namaOutfile[60];
						 sprintf(namaOutfile, "DataPerformaOCR Algoritma %d_%d.txt", pilihAlgoritma, metode);
						 outfile = fopen(namaOutfile, "w");
						 ptr = &logs[0];
						 fprintf(outfile, "No Citra\td1\td2\td3\td4\n");

						 for(iCitra = 1; iCitra < banyakCitra +1; iCitra++) {						 
							 cv::String teslagi = alamatFolder + "\\" + std::to_string(iCitra) + ".jpg";
							 CitraAwal = imread(alamatFolder + "\\" + std::to_string(iCitra) + ".jpg");						 
							 olahCitraSlmKlasifikasiDigit();
						 }						 
						 fclose(outfile);
					 }
				 }				 
			 }
	private: System::Void buttonCariBatas_Click(System::Object^  sender, System::EventArgs^  e) {
				 Mat CitraDigit;
				 int l, t, w, h, banyakPutih;
				 char* fileCitra;				 
				 cv::Size ukuranFrame1, ukuranFrame2;
				 ukuranFrame1 = cv::Size(30,71);
				 ukuranFrame2 = cv::Size(12,71);

				 char namaOutfile[60];

				 for(int mulai = 0; mulai <= 1; mulai++) {
					 switch (mulai) {
					 case 0:
						 fileCitra = "../citranol/";
						 sprintf(namaOutfile, "Nilai Piksel Putih Citra Nol.txt");
						 break;
					 case 1:							 
						 fileCitra = "../citrasatu/";
						 sprintf(namaOutfile, "Nilai Piksel Putih Citra Satu.txt");
						 break;
					 }					 
					 outfile = fopen(namaOutfile, "w");
					 ptr = &logs[0];
					 fprintf(outfile, "No Citra\tPiksel Putih\n");

					 System::String^ alamatFoldera;
					 alamatFoldera = gcnew System::String(fileCitra);					 					 
					 alamatFolder = MarshalString(alamatFoldera);
					 banyakCitra = System::IO::Directory::GetFiles(alamatFoldera)->Length;

					 for(iCitra = 1; iCitra < banyakCitra +1; iCitra++) {
						 Mat CitraOlah1, CitraDigit1;
						 CitraAwal = imread(alamatFolder + "\\" + std::to_string(iCitra) + ".jpg", CV_LOAD_IMAGE_GRAYSCALE);						 
						 equalizeHist(CitraAwal, CitraOlah1);
						 adaptiveThreshold(CitraOlah1, CitraOlah, 255.0, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 499, 0.0);
						 l = (int) (0.153 * CitraOlah.cols);
						 t = (int) (0.190 * CitraOlah.rows);
						 w = (int) (0.085 * CitraOlah.cols);
						 h = (int) (0.490 * CitraOlah.rows);							

						 Rect kotakDigit = Rect(l, t, w, h);										 
						 CitraDigit = Mat(CitraOlah, kotakDigit);
						 resize(CitraDigit, CitraDigit1, ukuranFrame2, 0.0, 0.0, INTER_CUBIC); //Untuk digit pertama						 
						 banyakPutih = countNonZero(CitraDigit1);

						 fprintf(outfile, "%d\t%d\n", iCitra, banyakPutih);
					 }
					 fclose(outfile);
				 }				
			 }
	private: System::Void buttonBuatTemplate_Click(System::Object^  sender, System::EventArgs^  e) {
				 olahCitraTemplate();
			 }

	private: System::Void buttonOlahTM_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (folderBrowserDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
					 int algoritmaPraPengolahan, algoritmaKlasifikasi;
					 int jenisOlah = 1;
					 cv::String fileTemplate;
					 for (algoritmaPraPengolahan = 1; algoritmaPraPengolahan <= 7; algoritmaPraPengolahan++) {
						 for (algoritmaKlasifikasi = 1; algoritmaKlasifikasi <= 6; algoritmaKlasifikasi++) {
							 switch (algoritmaPraPengolahan) {
							 case 1:
								 for (int d = 0; d <= 21; d++) {
									 fileTemplate = "../slmratabiner/s" + std::to_string(d) + ".jpg";								 
									 frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);
									 equalizeHist(frameDigitTemplate[d], frameDigitTemplate[d]);
									 frameDigitTemplate[d].convertTo(frameDigitTemplateF[d], CV_32F);
								 }
								 break;
							 case 2:
								 for (int d = 0; d <= 21; d++) {
									 fileTemplate = "../slmratabiner/s" + std::to_string(d) + ".jpg";
									 frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);
									 equalizeHist(frameDigitTemplate[d], frameDigitTemplate[d]);
									 frameDigitTemplate[d].convertTo(frameDigitTemplateF[d], CV_32F);
								 }
								 break;
							 case 3:
								 for (int d = 0; d <= 21; d++) {
									 fileTemplate = "../slmratagray/s" + std::to_string(d) + ".jpg";								 
									 frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);
									 equalizeHist(frameDigitTemplate[d], frameDigitTemplate[d]);
									 frameDigitTemplate[d].convertTo(frameDigitTemplateF[d], CV_32F);
								 }
								 break;
							 case 4:
								 for (int d = 0; d <= 21; d++) {
									 fileTemplate = "../slmratagrayekual/s" + std::to_string(d) + ".jpg";								 
									 frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);								 		
									 equalizeHist(frameDigitTemplate[d], frameDigitTemplate[d]);
									 frameDigitTemplate[d].convertTo(frameDigitTemplateF[d], CV_32F);
								 }
								 break;
							 case 5:
								 for (int d = 0; d <= 21; d++) {
									 fileTemplate = "../slmgray/s" + std::to_string(d) + ".jpg";								
									 frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);								 				
									 equalizeHist(frameDigitTemplate[d], frameDigitTemplate[d]);
									 frameDigitTemplate[d].convertTo(frameDigitTemplateF[d], CV_32F);
								 }
								 break;
							 case 6:
								 for (int d = 0; d <= 19; d++) {
									 fileTemplate = "../slmgrayekual/s" + std::to_string(d) + ".jpg";								
									 frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);								 				
									 equalizeHist(frameDigitTemplate[d], frameDigitTemplate[d]);
									 frameDigitTemplate[d].convertTo(frameDigitTemplateF[d], CV_32F);
								 }
								 break;
							 case 7:
								 for (int d = 0; d <= 21; d++) {
									 fileTemplate = "../slmratabiner/s" + std::to_string(d) + ".jpg";								
									 frameDigitTemplate[d] = imread(fileTemplate, CV_LOAD_IMAGE_GRAYSCALE);								 				
									 equalizeHist(frameDigitTemplate[d], frameDigitTemplate[d]);
									 frameDigitTemplate[d].convertTo(frameDigitTemplateF[d], CV_32F);
								 }
								 break;
							 }

							 statusGanti = 0;
							 //}

							 System::String^ alamatFoldera;
							 alamatFoldera = folderBrowserDialog->SelectedPath;
							 alamatFolder = MarshalString(folderBrowserDialog->SelectedPath);
							 banyakCitra = System::IO::Directory::GetFiles(alamatFoldera)->Length;

							 char namaOutfile[60];
							 sprintf(namaOutfile, "DataPerformaOCR Algoritma %d_%d.txt", algoritmaPraPengolahan, algoritmaKlasifikasi);
							 outfile = fopen(namaOutfile, "w");
							 ptr = &logs[0];
							 fprintf(outfile, "No Citra\td1\td2\td3\td4\n");							 

							 for(iCitra = 1; iCitra < banyakCitra +1; iCitra++) {								 
								 cv::String teslagi = alamatFolder + "\\" + std::to_string(iCitra) + ".jpg";
								 CitraAwal = imread(alamatFolder + "\\" + std::to_string(iCitra) + ".jpg");
								 olahCitra(algoritmaPraPengolahan, algoritmaKlasifikasi, jenisOlah);								 
							 }						 
							 fclose(outfile);
						 }
					 }
				 }
			 }
	};
}
