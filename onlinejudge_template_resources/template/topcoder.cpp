<%!
    import os
    import platform

    import onlinejudge_template.generator.cplusplus as cplusplus
    import onlinejudge_template.generator._topcoder as _topcoder
    import onlinejudge_template.generator.about as about
%>\
<%
    data['config']['rep_macro'] = 'REP'
    data['config']['using_namespace_std'] = True
    data['config']['long_long_int'] = 'int64_t'
    if platform.system() == 'Linux' and "clang" not in os.environ.get("CXX", "g++"):
        include = "#include <bits/stdc++.h>"
    else:
        include = "\n".join([
            "#include <iostream>",
            "#include <string>",
            "#include <vector>",
        ])
%>\
${include}
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;

${cplusplus.declare_constants(data)}
class ${_topcoder.class_name(data)} {
public:
    ${cplusplus.return_type(data)} ${_topcoder.method_name(data)}(${cplusplus.formal_arguments(data)}) {
    }
};

#ifdef LOCAL
// generated by ${about.title} ${about.version} (${about.url})
int main() {
${cplusplus.read_input(data)}
    auto ${cplusplus.return_value(data)} = ${_topcoder.class_name(data)}().${_topcoder.method_name(data)}(${cplusplus.actual_arguments(data)});
${cplusplus.write_output(data)}
    return 0;
}
#endif
