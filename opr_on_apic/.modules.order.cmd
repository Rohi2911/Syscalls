cmd_opr_on_apic/modules.order := {  :; } | awk '!x[$$0]++' - > opr_on_apic/modules.order
