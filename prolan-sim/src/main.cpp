#include <iostream>
#include <vector>
#include <string>

#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"

using namespace std;

int main()
{
	vector<mahasiswa> recMhs;
	vector<dosen> recDosen;
	vector<tendik> recTendik;

	int menu_terpilih;
    int idMhs = 0;
    int idDosen = 0;
    int idTendik = 0;

	while(1) {
		cout << "Selamat Datang di Institut Teknologi Sepuluh Nopember" << endl << endl;
		cout << "Data Statistik:" << endl;
		cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << " Mahasiswa" << endl;
		cout << "  2. Jumlah Dosen                 : " << recDosen.size() << " Dosen" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " Tenaga Kependidikan" << endl;
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tambah Mahasiswa" << endl;
		cout << "  2. Tambah Dosen" << endl;
		cout << "  3. Tambah Tenaga Kependidikan" << endl;
		cout << "  4. Tampilkan Semua Mahasiswa" << endl;
		cout << "  5. Tampilkan Semua Dosen" << endl;
		cout << "  6. Tampilkan Semua Tenaga Kependidikan" << endl;
		cout << "-> Silahkan Memilih Salah Satu: ";
		cin >> menu_terpilih;

		switch (menu_terpilih) {
			case 1:{
                idMhs++;
                string id, nama, nrp, departemen, fakultas;
                int dd, mm, yy, tahunmasuk, jumlahmk;
                vector<string> matkul;
                id = idMhs;
                cout << "masukkan nama mahasiswa : ";
                cin.ignore();
                getline(cin, nama);
                cout << "masukkan tanggal lahir  : ";
                cin >> dd;
                cout << "masukkan bulan lahir    : ";
                cin >> mm;
                cout << "masukkan tahun lahir    : ";
                cin >> yy;
                cout << "masukkan nrp            : ";
                cin >> nrp;
                cout << "masukkan fakultas       : ";
                cin.ignore();
                getline(cin, fakultas);
                cout << "masukkan departemen     : ";
                cin.ignore();
                getline(cin, departemen);
                cout << "masukkan tahun masuk    : ";
                cin >> tahunmasuk;
                cout << "masukkan jumlah mata kuliah yang dipelajari :";
                cin >> jumlahmk;
                cin.ignore();
                for(int i=0; i<jumlahmk; i++)
                {
                    string temp;
                    cout << "Mata Kuliah Ke-" << i+1 << ": ";
                    getline(cin,temp);
                    matkul.push_back(temp);
                }
                mahasiswa inputMhs = mahasiswa(id, nama, dd, mm, yy, nrp, departemen, tahunmasuk, fakultas, matkul);
                recMhs.push_back(inputMhs);
            }
				break;
			case 2: {
				idDosen++;
                string id, nama, npp, departemen,pendidikan, fakultas, MTKL;
                int dd, mm, yy;
                id = idDosen;
                cout << "masukkan nama Dosen    : ";
                cin.ignore();
                getline(cin, nama);
                cout << "masukkan tanggal lahir : ";
                cin >> dd;
                cout << "masukkan bulan lahir   : ";
                cin >> mm;
                cout << "masukkan tahun lahir   : ";
                cin >> yy;
                cout << "masukkan npp           : ";
                cin >> npp;
                cout << "masukkan fakultas      : ";
                cin.ignore();
                getline(cin, fakultas);
                cout << "masukkan departemen    : ";
                cin.ignore();
                getline(cin, departemen);
                cout << "masukkan pendidikan    : ";
                cin.ignore();
                getline(cin, pendidikan);
                cout << "masukkan mata kuliah yang diajar oleh dosen : ";
                getline(cin, MTKL);

                dosen inputDosen = dosen(id, nama, dd, mm, yy, npp, departemen, pendidikan, fakultas, MTKL);
                recDosen.push_back(inputDosen);
			}
				break;
			case 3:{
				idTendik++;
                string id, nama, npp, unit;
                int dd, mm, yy;
                id = idTendik;
                cout << "masukkan nama tendik   : ";
                cin.ignore();
                getline(cin, nama);
                cout << "masukkan tanggal lahir : ";
                cin >> dd;
                cout << "masukkan bulan lahir   : ";
                cin >> mm;
                cout << "masukkan tahun lahir   : ";
                cin >> yy;
                cout << "masukkan npp           : ";
                cin >> npp;
                cout << "masukkan unit          : ";
                cin.ignore();
                getline(cin, unit);
                tendik inputTendik = tendik(id, nama, dd, mm, yy, npp, unit);
                recTendik.push_back(inputTendik);
			}

                break;    
			case 4:{
                for(int i = 0; i < idMhs; i++){
                    cout << "Nama Mahasiswa :" << recMhs[i].getNama() << endl;
					cout << "Tanggal Lahir  :" << recMhs[i].getTglLahir() <<  "/"<<recMhs[i].getBulanLahir()<< "/" << recMhs[i].getTahunLahir() <<endl;
					cout << "NRP            :" << recMhs[i].getNRP() << endl;
                    cout << "Fakultas       :" << recMhs[i].getFakukltas() << endl;
					cout << "Departemen     :" << recMhs[i].getDepartemen() << endl;
					cout << "Tahun Masuk    :" << recMhs[i].getTahunMasuk() << endl << endl;
                    cout << "Mata Kuliah    : " << endl;
                    vector<string> temp = recMhs[i].getMatkul();
                    for(long unsigned int j=0; j<temp.size(); j++)
                    {
                        cout<<j+1<<". "<<temp[j]<<endl;
                    }
                    
                }
            }
				break;
			case 5:{
				  for(int i = 0; i < idDosen; i++){
                    cout << "Nama Dosen                :" << recDosen[i].getNama() << endl;
                    cout << "Tanggal Lahir             :" << recDosen[i].getTglLahir() <<  "/"<<recDosen[i].getBulanLahir()<< "/" << recDosen[i].getTahunLahir() <<endl;
                    cout << "NPP                       :" << recDosen[i].getNPP() << endl;
                    cout << "Fakultas                  :" << recDosen[i].getFakultas() << endl;
                    cout << "Departemen                :" << recDosen[i].getDepartemen() << endl;
                    cout << "Pendidikan                :" << recDosen[i].getPendidikan() << endl << endl;
                    cout << "Mata Kuliah Yang Diajar   : "<<recDosen[i].getMTKL()<< endl;
                    
                }
			}
				break;
			case 6:{
				  for(int i = 0; i < idTendik; i++){
                    cout << "Nama Tendik    :" << recTendik[i].getNama() << endl;
					cout << "Tanggal Lahir  :" << recTendik[i].getTglLahir() <<  "/"<<recTendik[i].getBulanLahir()<< "/" << recTendik[i].getTahunLahir() <<endl;
					cout << "NPP            :" << recTendik[i].getNPP() << endl;
					cout << "Unit           :" << recTendik[i].getUnit() << endl;
                }
			}
                break;
		}
	}
}
