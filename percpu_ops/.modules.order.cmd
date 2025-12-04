cmd_percpu_ops/modules.order := {  :; } | awk '!x[$$0]++' - > percpu_ops/modules.order
