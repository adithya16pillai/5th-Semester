import ipaddress

def split_network(ip_network, num_subnets):
    subnets = list(ip_network.subnets(prefixlen_diff=num_subnets))
    return subnets

def print_subnet_details(subnets):
    for subnet in subnets:
        print("CIDR: {}".format(subnet))
        print("Start Address: {}".format(subnet.network_address))
        print("End Address: {}".format(subnet.broadcast_address))
        print()

def main():
    ip_network = ipaddress.ip_network("192.168.200.0/24")
    num_subnets = 4

    subnets = split_network(ip_network, num_subnets)
    print_subnet_details(subnets)

if __name__ == "__main__":
    main()
