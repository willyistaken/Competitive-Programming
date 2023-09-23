inline ll modmul(ll a, ll b) {
	ll ret = a * b - MOD * ll(1.L / MOD * a * b);
	return ret + MOD * (ret < 0) - MOD * (ret >= (ll)MOD);
}
