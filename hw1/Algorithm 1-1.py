N, M = map(int, input().split())
world = [[i + 1] for i in range(N)]

# Initial site_map by each blocks position in world
site_map = {}
for i in range(N):
    site_map[i + 1] = i


def reset(site, until):
    for i in range(len(world[site]) - 1, -1, -1):
        if world[site][i] == until:
            world[site] = world[site][:i + 1]
            break
        top = world[site][i]
        world[top-1].append(top)
        site_map[top] = top-1


def stack(from_site, from_tar, to_site):
    global world
    tar_ind = len(world[from_site]) - 1
    while world[from_site][tar_ind] != from_tar:
        site_map[world[from_site][tar_ind]] = to_site
        tar_ind -= 1
    site_map[world[from_site][tar_ind]] = to_site
    world[to_site] = world[to_site] + world[from_site][tar_ind:]
    world[from_site] = world[from_site][:tar_ind]


for i in range(M):

    direct = input().split(' ')
    a_block, b_block = int(direct[1]), int(direct[3])

    if (a_block >= 1 and b_block >= 1) and (a_block <= N and b_block <= N):

        a_site, b_site = site_map[a_block], site_map[b_block]

        if a_site != b_site:
            if (direct[0] == "move") & (direct[2] == "onto"):
                reset(a_site, a_block)
                reset(b_site, b_block)
                stack(a_site, a_block, b_site)

            elif (direct[0] == "move") & (direct[2] == "over"):
                reset(a_site, a_block)
                stack(a_site, a_block, b_site)

            elif (direct[0] == "pile") & (direct[2] == "onto"):
                reset(b_site, b_block)
                stack(a_site, a_block, b_site)

            elif (direct[0] == "pile") & (direct[2] == "over"):
                stack(a_site, a_block, b_site)

for i in range(len(world)):
    print(str(i + 1) + ':', *world[i])
