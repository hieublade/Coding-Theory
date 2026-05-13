#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

bool isSingular(const vector<string>& code) {
    set<string> unique_codewords(code.begin(), code.end());
    return unique_codewords.size() < code.size();
}

bool isPrefixCode(const vector<string>& code) {
    for (size_t i = 0; i < code.size(); ++i) {
        for (size_t j = 0; j < code.size(); ++j) {
            if (i != j && code[j].find(code[i]) == 0) return false;
        }
    }
    return true;
}

bool isUniquelyDecodable(const vector<string>& code, int output_mode) {
    if (isSingular(code)) {
        if (output_mode == 2) cout << "    -> Vi ma bi suy bien nen khong the giai ma duy nhat.\n";
        return false;
    }

    // Ở chế độ tự luận (2), chúng ta vẫn chạy Sardinas-Patterson 
    // ngay cả khi là mã prefix để xem S1 = rỗng.
    if (isPrefixCode(code) && output_mode != 2) {
         return true;
    }

    set<string> c(code.begin(), code.end());
    set<string> s; 

    // 1. Khởi tạo S1
    for (const string& w1 : c) {
        for (const string& w2 : c) {
            if (w1 != w2 && w1.find(w2) == 0) {
                s.insert(w1.substr(w2.length()));
            }
        }
    }

    set<string> seen = s; // Lưu lại các hậu tố đã sinh để chống lặp vô hạn
    int step = 1;

    // Nếu S1 rỗng ngay từ đầu
    if (s.empty()) {
        if (output_mode == 2) cout << "    -> Tap S1: { rong }\n    -> Ket luan: Giai ma duy nhat.\n";
        return true;
    }

    while (true) {
        if (output_mode == 2) {
            cout << "    -> Tap S" << step << ": { ";
            for (auto it = s.begin(); it != s.end(); ++it) {
                cout << *it << (next(it) == s.end() ? "" : ", ");
            }
            cout << " }\n";
        }

        set<string> next_s;
        for (const string& w : c) {
            for (const string& suf : s) {
                // TH1: Tu ma la tien to cua hau to (w là tiền tố của suf)
                if (suf.find(w) == 0) {
                    string res = suf.substr(w.length());
                    if (res.empty()) continue; // Đã check trùng ở bước giao C và Sn
                    if (c.count(res)) {
                        if (output_mode == 2) cout << "    !! Tim thay hau to '" << res << "' trung voi tu ma trong C.\n";
                        return false;
                    }
                    next_s.insert(res);
                }
                // TH2: Hau to la tien to cua tu ma (suf là tiền tố của w)
                if (w.find(suf) == 0) {
                    string res = w.substr(suf.length());
                    if (res.empty()) continue;
                    if (c.count(res)) {
                        if (output_mode == 2) cout << "    !! Tim thay hau to '" << res << "' trung voi tu ma trong C.\n";
                        return false;
                    }
                    next_s.insert(res);
                }
            }
        }

        // Kiểm tra điều kiện dừng: Tập tiếp theo rỗng
        if (next_s.empty()) {
            if (output_mode == 2) cout << "    -> Tap S" << step + 1 << ": { rong }\n";
            return true;
        }

        // Kiểm tra điều kiện dừng: Không có hậu tố mới (Lặp chu trình)
        bool added_new = false;
        for (const string& ns : next_s) {
            if (seen.insert(ns).second) added_new = true;
        }

        if (!added_new) {
            if (output_mode == 2) cout << "    -> Tap S" << step + 1 << " khong chua hau to moi so voi cac tap truoc.\n";
            return true;
        }

        s = next_s;
        step++;
    }
}

void solve() {
    int output_mode;
    if (!(cin >> output_mode)) return; 

    int t;
    cin >> t; 
    
    for (int i = 1; i <= t; ++i) {
        int n;
        cin >> n;
        vector<string> code(n);
        for (int j = 0; j < n; ++j) cin >> code[j];

        if (output_mode == 2) {
            cout << "\n=== TEST CASE " << i << " ===\n";
            cout << "Bo ma C = { ";
            for (int j = 0; j < n; ++j) cout << code[j] << (j == n - 1 ? "" : ", ");
            cout << " }\n";
            cout << "[Kiem tra Sardinas-Patterson]\n";
        }

        bool singular = isSingular(code);
        bool uniquely_decodable = isUniquelyDecodable(code, output_mode);
        bool prefix = isPrefixCode(code);

        if (output_mode == 1) {
            cout << "Test " << i << ": ";
            cout << (singular ? "Suy bien - YES, " : "Suy bien - NO, ");
            cout << (uniquely_decodable ? "GMDN - YES, " : "GMDN - NO, ");
            cout << (prefix ? "Prefix - YES" : "Prefix - NO") << "\n";
        } else {
            cout << "==> Ket luan:\n";
            cout << " (a) Suy bien: " << (singular ? "YES" : "NO") << "\n";
            cout << " (b) GMDN:     " << (uniquely_decodable ? "YES" : "NO") << "\n";
            cout << " (c) Prefix:   " << (prefix ? "YES" : "NO") << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}