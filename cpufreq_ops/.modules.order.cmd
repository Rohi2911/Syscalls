cmd_cpufreq_ops/modules.order := {  :; } | awk '!x[$$0]++' - > cpufreq_ops/modules.order
