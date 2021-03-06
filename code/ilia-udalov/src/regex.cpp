#include "../include/regex.hpp"

int matchStar(int c, const std::string& regex, const std::string& text, size_t r, size_t t);
int matchHere(const std::string& regex, const std::string& text, size_t r, size_t t);

int match(const std::string& regex, const std::string& text) {
    size_t r_pos = 0;
    size_t t_pos = 0;
    if ((regex.size() > 0) && (regex[r_pos] == '^')) {
        return matchHere(regex, text, r_pos + 1, t_pos);
    }
    do {
        if (matchHere(regex, text, r_pos, t_pos))
            return 1;
    } while (t_pos++ != text.size());
    return 0;
}

int matchHere(const std::string& regex, const std::string& text, size_t r_pos, size_t t_pos) {
    if (r_pos == regex.size())
        return 1;
    if (regex[r_pos + 1] == '*')
        return matchStar(regex[r_pos], regex, text, r_pos + 2, t_pos);
    if (regex[r_pos] == '$' && regex.size() == r_pos)
        return t_pos == text.size();
    if (t_pos != text.size() && (regex[r_pos] == '.' || regex[r_pos] == text[t_pos]))
        return matchHere(regex, text, r_pos + 1, t_pos + 1);
    return 0;
}

int matchStar(int c, const std::string& regex, const std::string& text, size_t r_pos, size_t t_pos) {
    do {
        if (matchHere(regex, text, r_pos, t_pos))
            return 1;
    } while (t_pos != text.size() && (text[t_pos++] == c || c == '.'));
    return 0;
}

int find(const std::string& substring, const std::string& text) {
    return 0;
}