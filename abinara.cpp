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
        }

        void display(){
            cout << "Nama   : " << Nama << endl;
            cout << "NRP    : " << NRP << endl;
            cout << "TO1    : " << TryOut1 << endl;
            cout << "TO2    : " << TryOut2 << endl;
            cout << "TO3    : " << TryOut3 << endl;
            cout << "Kampus : " << Kampus << endl;
            cout<< "Jurusan : " << Jurusan << endl;
            cout << "Lulus  : " << Lulus << "%" << endl;
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
bool cekNRP(ll np) {
    for (const auto& d : data) {
        if (d.NRP == np) {
            return false; // NRP sudah ada
        }
    }
    return true; // NRP belum ada
}
void masuk(){
    string nama, kampus,jurusan;
    ll NP,TO1,TO2,TO3;
    int n;
    bool valid = false;
    cout<<"Masukkan 1 untuk lanjut memasukkan data\nMasukkan 0 untuk selesai memasukkan data\nInput = ";
    cin>>n;
    while(!valid){
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
            bool valdi=false;
            while(!valdi){
                cout<<"Apakah ingin lanjut ke sesi selanjutnya?\n Masukkan 10 untuk memasukkan data\nMasukkan 11 untuk memodifikasi data\nMasukkan 12 untuk menghapus data\nMasukkan 13 untuk menyelesaikan sesi\nInput = ";
                cin>>n;
                switch(n){
                    case 10:{
                        for(auto& d : data){
                            d.display();
                        }
                        masuk();
                        return;
                    }case 11:{
                        valdi = true;
                        for(auto& d : data){
                            d.display();
                        }
                        modifikasi();
                        return;
                    }case 12:{
                        valdi = true;
                        for(auto& d : data){
                            d.display();
                        }
                        apus();
                        return;
                    }case 13:{
                        valdi = true;
                        return;
                    }default:{
                        cout<<"Opsi tidak valid"<<endl;
                        break;
                    }
                }
            }
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
                    case 2:{
                        cout<<"Masukkan NRP = ";
                        cin>>d.NRP;
                        cout<<"Data Berhasil Diubah"<<endl;
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
                        goto nextstep;
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
            goto nextstep;
        }
        
    }

nextstep:
    bool valdi=false;
    while (!valdi){
        cout<<"Apakah ingin lanjut ke sesi selanjutnya?\n Masukkan 10 untuk memasukkan data\nMasukkan 11 untuk memodifikasi data\nMasukkan 12 untuk menghapus data\nMasukkan 13 untuk menyelesaikan sesi\nInput = ";
        cin>>np;
        switch (np){
            case 10:{
                valdi=true;
                masuk();
                return;
            }
            case 11:{
                valdi=true;
                modifikasi();
                return;
            }
            case 12:{
                valdi=true;
                apus();
                return;
            }
            case 13:{
                valdi=true;
                return;
            }
            default:{
                valdi=false;
                cout<<"Opsi tidak valid"<<endl;
                break;
            }
        }
    }
}
void apus(){
    if(data.empty()){
        cout<<"Anda belum memasukkan data, silahkan input beberapa data terlebih dahulu"<<endl;
        masuk();
        return;
    }
    string nama;
    ll nrp;
    int n;
    bool ada = false;
    cout<<"Masukkan nama dan nrp yang akan diapus"<<endl<<"Nama = ";
    cin>>nama;cout<<"NRP = ";cin>>nrp;cout<<endl;

    for(auto d = data.begin();d!=data.end();++d){
        if(d->Nama==nama && d->NRP==nrp){
            data.erase(d);
            cout<<"Data siswa atas nama "<<nama<<" dan dengan NRP "<<nrp<<" berhasil dihapus"<<endl;
            ada = true;
            break;
        }
    }


    if(!ada){
        cout<<"Data siswa atas nama "<<nama<<" dan dengan NRP "<<nrp<<" tidak ditemukan"<<endl;
        cout<<endl<<"Masukkan satu di antara opsi berikut\n1 = Coba lagi\n2 = Kembali ke menu utama\nInput pilihan = ";
        cin>>n;
        switch(n){
            case 1:{
                apus();
                return;
            }
            case 2:{
                bool valdi=false;
                    while(!valdi){
                        cout<<"Apakah ingin lanjut ke sesi selanjutnya?\nMasukkan 10 untuk memasukkan data\nMasukkan 11 untuk memodifikasi data\nMasukkan 12 untuk menghapus data\nMasukkan 13 untuk mengakhiri sesi\nInput = ";
                        switch(n){
                            case 10:{
                                valdi = true;
                                for(auto& d : data){
                                    d.display();
                                }
                                masuk();
                                break;
                            }case 11:{
                                valdi = true;
                                for(auto& d : data){
                                    d.display();
                                }
                                modifikasi();
                                break;
                            }case 12:{
                                valdi = true;
                                for(auto& d : data){
                                    d.display();
                                }
                                apus();
                                break;
                            }default:{
                                valdi = false;
                                cout<<"Opsi tidak valid"<<endl;
                                break;
                            }
                        }
                    }
            }
        }

    }else{
        cout<<endl<<"Masukkan satu di antara opsi berikut\n1 = Coba lagi\n2 = Kembali ke menu utama\nInput pilihan = ";
        cin>>n;
        switch(n){
            case 1:{
                apus();
                break;
            }
            case 2:{
                bool valdi=false;
                    while(!valdi){
                        cout<<"Apakah ingin lanjut ke sesi selanjutnya?\n Masukkan 10 untuk memasukkan data\nMasukkan 11 untuk memodifikasi data\nMasukkan 12 untuk menghapus data\nMasukkan 13 untuk mengakhiri sesi\nInput = ";
                        switch(n){
                            case 10:{
                                valdi = true;
                                masuk();
                                break;
                            }case 11:{
                                valdi = true;
                                modifikasi();
                                break;
                            }case 12:{
                                valdi = true;
                                apus();
                                break;
                            }case 13:{
                                valdi = true;
                                return;
                            }default:{
                                cout<<"Opsi tidak valid"<<endl;
                                break;
                            }
                        }
                    }
            }
        }
    }

}

int main(){
    int n;
    bool valid=false;
    while(true){
        cout<<"Ketik 1 untuk input data\nKetik 2 untuk selanjutnya ubah data\nKetik 3 untuk hapus data\nKetik 0 untuk mengakhiri sesi\nInput = ";
        cin>>n;

        if(n==1){
            valid = true;
            masuk();
            for(auto& d : data){
                d.display();
            }
        }else if(n==2){
            valid = true;
            modifikasi();
            for(auto& d : data){
                d.display();
            }
        }else if(n==3){
            valid = true;
            apus();
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