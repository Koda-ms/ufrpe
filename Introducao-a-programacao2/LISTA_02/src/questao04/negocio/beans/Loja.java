package questao04.negocio.beans;

import java.util.Objects;

public class Loja{
	
	private String cnpj;
	private String nome;
	private String site;

	public Loja(String cnpj, String nome, String site) {
		this.setCnpj(cnpj);
		this.setNome(nome);
		this.setSite(site);
	}

	public String getCnpj() {
		return cnpj;
	}

	public void setCnpj(String cnpj) {
		if(cnpj != null) {
			this.cnpj = cnpj;
		}
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		if(nome != null) {
			this.nome = nome;
		}
	}

	public String getSite() {
		return site;
	}

	public void setSite(String site) {
		if(site != null) {
			this.site = site;
		}
	}
	
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Loja other = (Loja) obj;
		return Objects.equals(cnpj, other.cnpj) && Objects.equals(nome, other.nome) && Objects.equals(site, other.site);
	}

	@Override
	public String toString() {
		return "Loja [cnpj=" + cnpj + ", nome=" + nome + ", site=" + site + "]";
	}
}
