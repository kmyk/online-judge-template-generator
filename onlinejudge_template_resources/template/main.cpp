<%!
    import json
    import os
    import platform
    import shutil
    from logging import getLogger

    import onlinejudge_template.generator.cplusplus as cplusplus
    import onlinejudge_template.generator.topcoder as topcoder
    import onlinejudge_template.generator.about as about
    import onlinejudge_template.generator.hook as hook
%>\
<%
    logger = getLogger(__name__)
    data["config"]["rep_macro"] = "REP"
    data["config"]["using_namespace_std"] = True
    data["config"]["long_long_int"] = "int64_t"
    if platform.system() == "Linux" and "clang" not in os.environ.get("CXX", "g++"):
        include = "#include <bits/stdc++.h>"
    else:
        include = "\n".join([
            "#include <iostream>",
            "#include <string>",
            "#include <vector>",
        ])
    if not shutil.which("clang-format"):
        logger.warning("clang-format is not installed. If you want to generate well-formatted code, please install it. If you use Ubuntu, you can run $ sudo apt install clang-format")
    else:
        format_config = {
            "BasedOnStyle": "Google",
            "IndentWidth": 4,
            "ColumnLimit": 9999,
            "ForEachMacros": ["REP", "REP3", "REP_R", "REP3R"],
        }
        hook.register_filter_command(["clang-format", "--style", json.dumps(format_config)], data=data)
%>\
${include}
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;

${cplusplus.declare_constants(data)}
% if topcoder.is_topcoder(data):
<% solve_function = topcoder.class_name(data) + "()." + topcoder.method_name(data) %>\
class ${topcoder.class_name(data)} {
public:
    ${cplusplus.return_type(data)} ${topcoder.method_name(data)}(${cplusplus.formal_arguments(data)}) {
        // TODO: edit here
    }
};
% else:
<% solve_function = "solve" %>\
${cplusplus.return_type(data)} solve(${cplusplus.formal_arguments(data)}) {
    // TODO: edit here
}
% endif

// generated by ${about.title} ${about.version} (${about.url})
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    constexpr char endl = '\n';
${cplusplus.read_input(data)}
    auto ${cplusplus.return_value(data)} = ${solve_function}(${cplusplus.actual_arguments(data)});
${cplusplus.write_output(data)}
    return 0;
}
