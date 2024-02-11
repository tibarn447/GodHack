echo "Easy Decomp Installer"
echo ""
echo "Installable repositories:"
echo "0) pokeemerald"
echo "1) pokeemerald-expansion"
echo "2) pokefirered"
echo "3) pokeruby"
echo "4) pokered"
echo "5) pokeyellow"
echo "6) pokegold"
echo "7) pokecrystal"
echo "8) poketcg"
echo "9) pokepinball"


id=-1
until [ $id -ge 0 ] && [ $id -lt 10 ]; do
	read -p "Select decomp/disassembly to download(0-9): " id
done

urls=(
	https://github.com/pret/pokeemerald
	https://github.com/rh-hideout/pokeemerald-expansion
	https://github.com/pret/pokefirered
	https://github.com/pret/pokeruby
	
	https://github.com/pret/pokered
	https://github.com/pret/pokeyellow
	https://github.com/pret/pokegold
	https://github.com/pret/pokecrystal
	https://github.com/pret/poketcg
	https://github.com/pret/pokepinball
)

repo_dir=$(basename ${urls[$id]})
if [ -d $repo_dir ]; then
	echo "$repo_dir is already downloaded!"
	exit
fi

if ! git clone ${urls[$id]}; then
	echo "Failed to clone repo! Try again later."
	exit
fi

if [ $id -lt 4 ]; then # decomp
	cp -r dep/agbcc $repo_dir/tools
fi
cp dep/scripts/_make.bat $repo_dir/
cp dep/scripts/_bash.bat $repo_dir/

echo "Compiling..."
if cd $repo_dir && make -j$(nproc); then
	echo "$repo_dir setup completed!"
else
	echo ""
	echo "Failed to compile the repo!"
	echo "Consider using another installation method instead of this."
fi
