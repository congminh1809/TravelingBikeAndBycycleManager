// TravelingBikeAndBycycleManager.cpp 

#include<iostream>
using namespace std;
#include<string>
#include<conio.h>

// khai báo lớp cha: class XE
class XE
{
protected:
	string HoTenNguoiThue;
	float SoGioThue;

public:

	void NhapThongTin()
	{
		while (getchar() != '\n'); // xóa bộ nhớ đệm trước khi nhập chuỗi
		cout << "\nNhap ho ten nguoi thue: ";
		getline(cin, HoTenNguoiThue);
		cout << "\nNhap so gio thue: ";
		cin >> SoGioThue;
	}
	void XuatThongTin()
	{
		cout << "\nHo ten nguoi thue: " << HoTenNguoiThue;
		cout << "\nSo gio thue: " << SoGioThue;
	}
};

// khai báo lớp con: class XEDAP kế thừa lại class XE
class XEDAP : public XE
{
private:
public:

	float TinhTienThueXe()
	{
		return 10000 + ((SoGioThue - 1) * 8000);
	}
};


// khai báo lớp con: class XEMAY kế thừa lại class XE
class XEMAY : public XE
{
private:

	int LoaiXe;
	string BienSo;

public:

	void NhapThongTin()
	{
		XE::NhapThongTin();
		cout << "\nNhap loai xe can thue(100 - 250 phan khoi): ";
		cin >> LoaiXe;
		while (getchar() != '\n'); // xóa bộ nhớ đệm trước khi nhập chuỗi
		cout << "\nNhap bien so: ";
		getline(cin, BienSo);

	}
	void XuatThongTin()
	{
		XE::XuatThongTin();
		cout << "\nLoai xe: " << LoaiXe;
		cout << "\nBien so: " << BienSo;
	}
	float TinhTienThueXe()
	{
		float s = 0;
		if (LoaiXe == 100)
		{
			s = 150000;
		}
		else
		{
			s = 200000;
		}
		return s + ((SoGioThue - 1) * 100000);
	}

	// GETTER - LOẠI XE
	int Getter_LoaiXe()
	{
		return LoaiXe;
	}
	void Setter_LoaiXe(int LOAIXE)
	{
		LoaiXe = LOAIXE;
	}

};

// phương thức xuất tất cả thông tin thuê xe
void Xuat_Tat_Ca_Thong_Tin_Thue_Xe(XEDAP ds_xedap[], int n, XEMAY ds_xemay[], int m)
{
	int dem = 1;
	cout << "\n\n\t\t DANH SACH THUE XE DAP\n" << endl;
	// xuất danh sách xe đạp
	for (int i = 0; i < n; i++)
	{
		cout << "\n\tTHONG TIN THUE XE DAP THU " << dem++ << endl;
		ds_xedap[i].XuatThongTin();
		cout << "\nTien thue: " << (size_t)ds_xedap[i].TinhTienThueXe() << endl;

	}

	cout << "\n\n\t\t DANH SACH THUE XE MAY\n" << endl;
	// xuất danh sách xe máy
	for (int i = 0; i < m; i++)
	{
		cout << "\n\tTHONG TIN THUE MAY THU " << dem++ << endl;
		ds_xemay[i].XuatThongTin();
		cout << "\nTien thue: " << (size_t)ds_xemay[i].TinhTienThueXe() << endl;
	}
}

// phương thức tính tổng tiền thuê xe đạp và xe máy
float Tinh_Tong_Tien_Thue_Xe(XEDAP ds_xedap[], int n, XEMAY ds_xemay[], int m)
{
	float tong = 0;
	// duyệt danh sách xe đạp
	for (int i = 0; i < n; i++)
	{
		tong += ds_xedap[i].TinhTienThueXe();

	}


	// duyệt danh sách xe máy
	for (int i = 0; i < m; i++)
	{
		tong += ds_xemay[i].TinhTienThueXe();
	}
	return tong;
}
// hàm quản lý các loại xe
void Menu(XEDAP ds_xedap[], int n, XEMAY ds_xemay[], int m)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ====== QUAN LY XE ======" << endl;
		cout << "\n\t1. Nhap danh sach thue xe dap va xe may" << endl;
		cout << "\n\t2. Xuat tat ca thong tin thue xe" << endl;
		cout << "\n\t3. Tinh tong so tien cho thue xe dap va xe may" << endl;
		cout << "\n\t4. Xuat tat ca cac thong tin lien quan den viec cho thue xe dap" << endl;
		cout << "\n\t5. Tinh tong so tien cho thue xe may loai 250 phan khoi" << endl;
		cout << "\n\t0. Ket thuc" << endl;
		cout << "\n\n\t\t ============== END ============" << endl;

		cout << "\nNhap lua chon: " << endl;
		cin >> luachon;

		if (luachon == 1)
		{
			int chon;
			while (true)
			{
				system("cls");

				cout << "\nNhap loai xe muon thue: " << endl;

				cout << "\n1. Thue XE DAP" << endl;
				cout << "\n2. Thue XE MAY" << endl;
				cout << "\n0. Ket thuc" << endl;

				//cout << "\nNhap loai xe muon thue: ";
				cin >> chon;

				if (chon == 1)
				{
					XEDAP x;
					cout << "\n\n\t\t NHAP THONG TIN THUE XE DAP\n" << endl;
					x.NhapThongTin();
					ds_xedap[n] = x;
					n++;
				}
				else if (chon == 2)
				{
					XEMAY x;
					cout << "\n\n\t\t NHAP THONG TIN THUE XE MAY\n" << endl;
					x.NhapThongTin();
					ds_xemay[m] = x;
					m++;
				}

				else
				{

					break;
				}
			}
		}
		else if (luachon == 2)
		{
			Xuat_Tat_Ca_Thong_Tin_Thue_Xe(ds_xedap, n, ds_xemay, m);
			system("pause");
		}
		else if (luachon == 3)
		{
			cout << "\n\n\t\tTONG TIEN THUE XE: " << (size_t)Tinh_Tong_Tien_Thue_Xe(ds_xedap, n, ds_xemay, m) << endl;
			system("pause");
		}
		else if (luachon == 4)
		{
			cout << "\n\n\t\t DANH SACH THUE XE DAP\n";
			// xuất danh sách xe đạp
			for (int i = 0; i < n; i++)
			{
				cout << "\n\tTHONG TIN THUE XE DAP THU " << i + 1 << endl;
				ds_xedap[i].XuatThongTin();
				cout << "\nTien thue: " << (size_t)ds_xedap[i].TinhTienThueXe() << endl;
			}
			system("pause");
		}
		else if (luachon == 5)
		{
			int dem = 0;
			cout << "\n\n\t\t DANH SACH THUE XE MAY LOAI 250 PHAN KHOI\n";
			// duyệt danh sách xe máy
			for (int i = 0; i < m; i++)
			{
				if (ds_xemay[i].Getter_LoaiXe() == 250)
				{
					cout << "\n\tTHONG TIN THUE MAY THU " << ++dem << endl;
					ds_xemay[i].XuatThongTin();
					cout << "\nTien thue: " << (size_t)ds_xemay[i].TinhTienThueXe() << endl;
				}
			}
			system("pause");
		}
		else
		{
			break;
		}
	}
}


int main()
{
	XEDAP ds_xedap[100];
	int n = 0;
	XEMAY ds_xemay[100];
	int m = 0;
	Menu(ds_xedap, n, ds_xemay, m);

	system("pause");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

