activities = {
    "A": {"duration": 11, "predecessors": []},
    "B": {"duration": 3, "predecessors": []},
    "C": {"duration": 10, "predecessors": []},
    "D": {"duration": 3, "predecessors": ["C"]},
    "E": {"duration": 1, "predecessors": ["B"]},
    "F": {"duration": 2, "predecessors": ["A"]},
    "G": {"duration": 1, "predecessors": ["E,G"]},
    "H": {"duration": 1, "predecessors": ["F,G"]}
}

def calculate_early_times(activities):
    ES = {}
    EF = {}

    for activity in activities:
        if not activities[activity]["predecessors"]:
            ES[activity] = 0
        else:
            ES[activity] = max(EF[p] for p in activities[activity]["predecessors"])
        EF[activity] = ES[activity] + activities[activity]["duration"]

    return ES, EF

def calculate_late_times(activities, EF):
    LS = {}
    LF = {}

    project_end_time = max(EF.values())

    for activity in reversed(activities):
        if activity not in activities.keys():
            continue
        LF[activity] = project_end_time if not activities[activity]["successors"] else min(LS[s] for s in activities[activity]["successors"])
        LS[activity] = LF[activity] - activities[activity]["duration"]

    return LS, LF


def identify_critical_path(activities, ES, EF, LS, LF):
    critical_path = []

    for activity in activities:
        if ES[activity] == LS[activity]:
            critical_path.append(activity)

    return critical_path


ES, EF = calculate_early_times(activities)
LS, LF = calculate_late_times(activities, EF)
critical_path = identify_critical_path(activities, ES, EF, LS, LF)

print("Critical Path:", critical_path)
print("Project Duration:", max(EF.values()))
