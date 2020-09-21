#include <fstream>

using namespace std;

string getIncludeName (string line)
{
    int start = line.find_first_of("\"");
    int end = line.find_last_of("\"");
    return "1_4_data/" + line.substr(start + 1, end - start - 1);
}

bool processFile (string file_in, string file_out)
{
    ifstream ifs (file_in.c_str(),ios::out);
    ofstream ofs (file_out.c_str(), ios::in | ofstream::trunc);
    string line;
    string line_include;
    if (!ofs.is_open() || !ifs.is_open()) {
        printf ("Could not open file\n");
        return false;
    } else {
        while (getline(ifs, line))
        {
            if (line.find ("#include") == 0)
            {
               printf ("filename = %s\n", getIncludeName(line).c_str());
               ifstream ifInclude (getIncludeName(line).c_str());
               if (ifInclude.is_open()) 
               {
                   while (getline(ifInclude, line_include))
                   {
                       ofs << line_include << "\n";
                   }
                   
               }
               ifInclude.close();
            }
            else {
                ofs << line << "\n";
            }
        }
        ifs.close();
        ofs.close();
    }
    return true;
}

int main(int argc, char* argv[])
{
    processFile ("1_4_data/file_in.txt", "1_4_data/file_out.txt");
    return 0;
}