#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void masuk();
void modifikasi();
void apus();

class siswa{
    public:
        string Nama,Kampus,Jurusan;
        ll NRP,TryOut1,TryOut2,TryOut3;
        double Lulus;
        siswa(string name,ll np, ll to1, ll to2, ll to3, string univ, string jurusan){
            Nama = name;
            NRP = np;
            TryOut1 = to1;
            TryOut2 = to2;
            TryOut3 = to3;
            Kampus = univ;
            Jurusan = jurusan;
            Lulus = 0.0;
        }

        void display(){
            cout << "Nama   : " << Nama << endl;
            cout << "NRP    : " << NRP << endl;
            cout << "TO1    : " << TryOut1 << endl;
            cout << "TO2    : " << TryOut2 << endl;
            cout << "TO3    : " << TryOut3 << endl;
            cout << "Kampus : " << Kampus << endl;
            cout<< "Jurusan : " << Jurusan << endl;
            cout << "Lulus  : " << (isnan(Lulus) ? 0.0 : Lulus) << "%" << endl;
            cout << "-------------------------" << endl;
        }
};
vector<siswa>data;
void irt(siswa& sis) {
    double a = (sis.TryOut1 + sis.TryOut2 + sis.TryOut3) / 3.0;
    if (sis.Kampus == "ITS" && sis.Jurusan == "TEKNOLOGI INFORMASI") {
        sis.Lulus = a / 500 * 60;
    } else if (sis.Kampus == "ITS" && sis.Jurusan == "TEKNIK MESIN") {
        sis.Lulus = a / 450 * 60;
    } else if (sis.Kampus == "UNAIR" && sis.Jurusan == "KEDOKTERAN") {
        sis.Lulus = a / 600 * 60;
    } else if (sis.Kampus == "UNAIR" && sis.Jurusan == "MANAJEMEN BISNIS") {
        sis.Lulus = a / 400 * 60;
    } else if (sis.Kampus == "ITB" && sis.Jurusan == "STEI") {
        sis.Lulus = a / 600 * 60;
    } else if (sis.Kampus == "ITB" && sis.Jurusan == "FTTM") {
        sis.Lulus = a / 600 * 60;
    } else if (sis.Kampus == "UI" && sis.Jurusan == "KEDOKTERAN") {
        sis.Lulus = a / 600 * 60;
    } else if (sis.Kampus == "UI" && sis.Jurusan == "FILSAFAT") {
        sis.Lulus = a / 500 * 60;
    } else if (sis.Kampus == "UGM" && sis.Jurusan == "KEDOKTERAN") {
        sis.Lulus = a / 600 * 60;
    } else if (sis.Kampus == "UGM" && sis.Jurusan == "Teknologi Informasi") {
        sis.Lulus = a / 550 * 60;
    }
}

void impor() {
    ofstream file("file.txt");
    if (file.is_open()) {
        for (const auto& d : data) {
            file << "Nama    : " << d.Nama << endl
                 << "NRP     : " << d.NRP << endl
                 << "TO1     : " << d.TryOut1 << endl
                 << "TO2     : " << d.TryOut2 << endl
                 << "TO3     : " << d.TryOut3 << endl
                 << "Kampus  : " << d.Kampus << endl
                 << "Jurusan : " << d.Jurusan << endl
                 << "Lulus   : " << d.Lulus << " %" << endl
                 << "-------------------------" << endl;
        }
        file.close();
        cout << "Data berhasil disimpan ke file.txt." << endl;
    } else {
        cout << "Gagal membuka file.txt" << endl;
    }
}


void expor() {
    ifstream file("file.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;

            string nama, kampus, jurusan;
            ll np, to1, to2, to3;
            double lulus;
            
            if (line.find("Nama    : ") == 0) {
                nama = line.substr(10);
                getline(file, line);
                np = stoll(line.substr(10));
                getline(file, line);
                to1 = stoll(line.substr(10));
                getline(file, line);
                to2 = stoll(line.substr(10));
                getline(file, line);
                to3 = stoll(line.substr(10));
                getline(file, line);
                kampus = line.substr(10);
                getline(file, line);
                jurusan = line.substr(10);
                getline(file, line);

                if (!line.empty()) {
                    try {
                        lulus = stod(line.substr(10));
                    } catch (const invalid_argument& e) {
                        cerr << "Error: Invalid data format for 'Lulus'." << endl;
                        continue;
                    }
                } else {
                    cerr << "Error: 'Lulus' line is empty." << endl;
                    continue;
                }

                siswa sis(nama, np, to1, to2, to3, kampus, jurusan);
                sis.Lulus = lulus;
                irt(sis);
                data.push_back(sis);
            }
        }
        file.close();
        cout << "Data berhasil dimuat dari file.txt." << endl;
    } else {
        cout << "File tidak ditemukan. Memulai dengan data kosong." << endl;
    }
}


bool cekNRP(ll np) {
    for (const auto& d : data) {
        if (d.NRP == np) {
            return false;
        }
    }
    return true;
}
void masuk(){
    for(auto& d : data){
        d.display();
    }
    string nama, kampus,jurusan;
    ll NP,TO1,TO2,TO3;
    int n;
    bool valid = false;
    
    while(!valid){
        cout<<"Masukkan 1 untuk lanjut memasukkan data\nMasukkan 0 untuk selesai memasukkan data\nInput = ";
        cin>>n;
        if(n==1){
            valid = true;
            cout << "Masukkan Nama: ";
            cin.ignore();
            getline(cin, nama);

            do {
                cout << "Masukkan NP: ";
                cin >> NP;
                if (!cekNRP(NP)) {
                    cout << "NRP sudah pernah diinput, coba lagi dengan NRP yang berbeda." << endl;
                }
            } while (!cekNRP(NP));

            cout << "Masukkan nilai TO1: ";cin >> TO1;
            cout << "Masukkan nilai TO2: ";cin >> TO2;
            cout << "Masukkan nilai TO3: ";cin >> TO3;

            cout << "Masukkan kampus tujuan: ";
            cin.ignore();
            getline(cin, kampus);

            cout << "Masukkan jurusan di kampus tujuan: ";
            getline(cin, jurusan);

            siswa input(nama, NP, TO1, TO2, TO3, kampus, jurusan);
            irt(input);
            data.push_back(input);
            masuk();
            return;
        }else if(n==0){
            valid = true;
            return;
        }else{
            valid=false;
            cout<<"Input tidak valid, coba lagi"<<endl;
            masuk();
            return;
        }
    }  
}
void modifikasi() {
    if(data.empty()){
        cout<<"Anda belum memasukkan data, silahkan input beberapa data terlebih dahulu"<<endl;
        masuk();
        return;
    }
    for(auto& d : data){
        d.display();
    }
    ll np;
    cout << "Masukkan NRP siswa yang ingin diganti = ";
    cin >> np;
    bool nemu = false;

    for (auto& d : data) {
        if (d.NRP == np) {
            nemu = true;
            int kom;

            while (true) {
                cout<<endl<<"Komponen apa yang ingin diganti dari NRP "<<np<<" ?"<<endl;
                cout<<"1 = Nama"<<endl;
                cout<<"2 = NRP"<<endl;
                cout<<"3 = Nilai TO1"<<endl;
                cout<<"4 = Nilai TO2"<<endl;
                cout<<"5 = Nilai TO3"<<endl;
                cout<<"6 = Kampus Tujuan"<<endl;
                cout<<"7 = Jurusan Tujuan"<<endl;
                cout<<"8 = Selesai Modifikasi"<<endl;
                cout<<"Input = ";
                cin>>kom;

                switch(kom){
                    case 1:{
                        cout<<"Masukkan Nama = ";
                        cin.ignore();
                        getline(cin, d.Nama);
                        cout<<"Data Berhasil Diubah"<<endl;
                        break;
                    }
                    case 2: {
                        ll nrpLama = d.NRP;
                        ll nrpBaru;
                        while (true) {
                            cout<<"Masukkan NP baru: ";
                            cin>>nrpBaru;
                            
                            if (nrpBaru!=nrpLama && !cekNRP(nrpBaru)) {
                                cout << "NRP sudah pernah diinput, coba lagi dengan NRP yang berbeda." << endl;
                            } else {
                                d.NRP = nrpBaru;
                                cout << "Data Berhasil Diubah" << endl;
                                break;
                            }
                        }
                        break;
                    }
                    case 3:{
                        cout<<"Masukkan Nilai TO1 = ";
                        cin>>d.TryOut1;
                        cout<<"Data Berhasil Diubah"<<endl;
                        irt(d);
                        break;
                    }
                    case 4:{
                        cout<<"Masukkan Nilai TO2 = ";
                        cin>>d.TryOut2;
                        cout<<"Data Berhasil Diubah" << endl;
                        irt(d);
                        break;
                    }
                    case 5:{
                        cout<<"Masukkan Nilai TO3 = ";
                        cin>>d.TryOut3;
                        cout<<"Data Berhasil Diubah"<<endl;
                        irt(d);
                        break;
                    }
                    case 6:{
                        cout<<"Masukkan Kampus Tujuan = ";
                        cin.ignore();
                        getline(cin, d.Kampus);
                        cout<<"Data Berhasil Diubah"<<endl;
                        irt(d);
                        break;
                    }
                    case 7:{
                        cout<<"Masukkan Jurusan di Kampus Tujuan = ";
                        cin.ignore();
                        getline(cin, d.Jurusan);
                        cout<<"Data Berhasil Diubah"<<endl;
                        irt(d);
                        break;
                    }
                    case 8:{
                        cout<<"Selesai memodifikasi data"<<endl;
                        return;
                    }
                    default:{
                        cout<<"Pilihan Tidak Valid"<<endl;
                        break;
                    }
                }
            }
        }
    }

    if (!nemu){
        cout<<"NRP tidak ditemukan"<<endl;
        cout<<"Ketikkan (***) untuk memasukkan NRP lagi atau ketik (###) untuk beralih ke sesi lain"<<endl;
        string hhh;cin>>hhh;
        if(hhh=="***"){
            modifikasi();
        }else if(hhh=="###"){
            return;
        }
        
    }
}
void apus() {
    if(data.empty()) {
        cout << "Anda belum memasukkan data, silahkan input beberapa data terlebih dahulu" << endl;
        masuk();
        return;
    }
    
    for(auto& d : data) {
        d.display();
    }

    string nama;
    ll nrp;
    int n;
    bool ada = false;
    cout << "Masukkan nama dan NRP yang akan dihapus" << endl;
    cout << "Nama = "; cin >> nama; cout << "NRP = "; cin >> nrp; cout << endl;

    for(auto d = data.begin(); d != data.end(); ++d) {
        if(d->Nama == nama && d->NRP == nrp) {
            data.erase(d);
            cout << "Data siswa atas nama " << nama << " dan dengan NRP " << nrp << " berhasil dihapus" << endl;
            ada = true;
            break;
        }
    }

    if(!ada) {
        cout << "Data siswa atas nama " << nama << " dan dengan NRP " << nrp << " tidak ditemukan" << endl;
    }

    while(true) {
        cout << endl << "Masukkan satu di antara opsi berikut\n1 = Coba lagi\n2 = Kembali ke menu utama\nInput pilihan = ";
        cin >> n;
        
        switch(n) {
            case 1: {
                apus();
                return;
            }
            case 2: {
                return;
            }
            default: {
                cout << "Opsi tidak valid, silakan coba lagi." << endl;
                break;
            }
        }
    }
}




int main(){
    expor();
    int n;
    bool valid=false;
    while(true){
        cout<<"Ketik 1 untuk input data\nKetik 2 untuk selanjutnya ubah data\nKetik 3 untuk hapus data\nKetik 0 untuk mengakhiri sesi\nInput = ";
        cin>>n;

        if(n==1){
            valid = true;
            masuk();
            impor();
            for(auto& d : data){
                d.display();
            }
        }else if(n==2){
            valid = true;
            modifikasi();
            impor();
            for(auto& d : data){
                d.display();
            }
        }else if(n==3){
            valid = true;
            apus();
            impor();
            for(auto& d : data){
                d.display();
            }
        }else if(n==0){
            break;
        }else{
            cout<<"Input tidak valid, coba lagi"<<endl;
            valid = false;
        }
    }

    cout<<"data akhir :"<<endl;
    for(auto& d : data){
        d.display();
    }

   return 0;
}